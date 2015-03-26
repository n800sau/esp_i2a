/*
Some random cgi routines. Used in the LED example and the page that returns the entire
flash as a binary. Also handles the hit counter on the main page.
*/

/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Jeroen Domburg <jeroen@spritesmods.com> wrote this file. As long as you retain 
 * this notice you can do whatever you want with this stuff. If we meet some day, 
 * and you think this stuff is worth it, you can buy me a beer in return. 
 * ----------------------------------------------------------------------------
 */

#include <string.h>
#include <osapi.h>
#include "user_interface.h"
#include <driver/uart.h>
#include <mem.h>
#include "httpd.h"
#include "cgi.h"
#include "io.h"
#include "base64.h"
#include <ip_addr.h>
#include "espmissingincludes.h"
#include "mmem.h"
#include <ets_sys.h>

//cause I can't be bothered to write an ioGetLed()
static char currLedState=0;

static long hitCounter=0;

//Template code for the counter on the index page.
void ICACHE_FLASH_ATTR tplCounter(HttpdConnData *connData, char *token, void **arg) {
	char buff[128];
	if (token==NULL) return;

	if (os_strcmp(token, "counter")==0) {
		hitCounter++;
		os_sprintf(buff, "%ld", hitCounter);
	}
	httpdSend(connData, buff, -1);
}


//Cgi that reads the SPI flash. Assumes 512KByte flash.
int ICACHE_FLASH_ATTR cgiReadFlash(HttpdConnData *connData) {
	int *pos=(int *)&connData->cgiData;
	if (connData->conn==NULL) {
		//Connection aborted. Clean up.
		return HTTPD_CGI_DONE;
	}

	if (*pos==0) {
		os_printf("Start flash download.\n");
		httpdStartResponse(connData, 200);
		httpdHeader(connData, "Content-Type", "application/bin");
		httpdEndHeaders(connData);
		*pos=0x40200000;
		return HTTPD_CGI_MORE;
	}
	//Send 1K of flash per call. We will get called again if we haven't sent 512K yet.
	espconn_sent(connData->conn, (uint8 *)(*pos), 1024);
	*pos+=1024;
	if (*pos>=0x40200000+(512*1024)) return HTTPD_CGI_DONE; else return HTTPD_CGI_MORE;
}

#define GPIO_L1 12
#define GPIO_L2 13

#define GPIO_R1 14
#define GPIO_R2 15

#define GPIO_S1 4
#define GPIO_S2 5

int cgiCommand(HttpdConnData *connData)
{
	const char *p = strrchr(connData->url, '/');
	os_printf("p=%s\n", p);
	if(os_strcmp(p+1, "mv_stop") == 0) {
		set_gpio(GPIO_L1, 0);
		set_gpio(GPIO_L2, 0);
		set_gpio(GPIO_R1, 0);
		set_gpio(GPIO_R2, 0);
		os_printf("Stop\n");
	} else if(os_strcmp(p+1, "mv_fwd") == 0) {
		set_gpio(GPIO_L1, 0);
		set_gpio(GPIO_L2, 1);
		set_gpio(GPIO_R1, 0);
		set_gpio(GPIO_R2, 1);
		os_printf("Forward\n");
	} else if(os_strcmp(p+1, "mv_back") == 0) {
		set_gpio(GPIO_L1, 1);
		set_gpio(GPIO_L2, 0);
		set_gpio(GPIO_R1, 1);
		set_gpio(GPIO_R2, 0);
		os_printf("Back\n");
	} else if(os_strcmp(p+1, "t_left") == 0) {
		set_gpio(GPIO_L1, 0);
		set_gpio(GPIO_L2, 1);
		set_gpio(GPIO_R1, 1);
		set_gpio(GPIO_R2, 0);
		os_printf("Left\n");
	} else if(os_strcmp(p+1, "t_right") == 0) {
		set_gpio(GPIO_L1, 1);
		set_gpio(GPIO_L2, 0);
		set_gpio(GPIO_R1, 0);
		set_gpio(GPIO_R2, 1);
		os_printf("Right\n");
	} else if(os_strcmp(p+1, "sh_stop") == 0) {
		set_gpio(GPIO_S1, 0);
		set_gpio(GPIO_S2, 0);
		os_printf("Middle stop\n");
	} else if(os_strcmp(p+1, "sh_up") == 0) {
		set_gpio(GPIO_S1, 1);
		set_gpio(GPIO_S2, 0);
		os_printf("Middle up\n");
	} else if(os_strcmp(p+1, "sh_down") == 0) {
		set_gpio(GPIO_S1, 0);
		set_gpio(GPIO_S2, 1);
		os_printf("Middle down\n");
	}
	httpdStartResponse(connData, 200);
	httpdHeader(connData, "Content-Type", "application/json");
	httpdEndHeaders(connData);
	httpdSend(connData, "{\"result\": \"Ok\"}", -1);
	return HTTPD_CGI_DONE;
}

