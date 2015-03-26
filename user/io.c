
/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * Jeroen Domburg <jeroen@spritesmods.com> wrote this file. As long as you retain 
 * this notice you can do whatever you want with this stuff. If we meet some day, 
 * and you think this stuff is worth it, you can buy me a beer in return. 
 * ----------------------------------------------------------------------------
 */


#include "c_types.h"
#include "user_interface.h"
#include "espconn.h"
#include "mem.h"
#include "io.h"
#include "osapi.h"
#include <gpio.h>
#include "espmissingincludes.h"

typedef struct _io {
	int n;
	int io_id;
	int io_mux;
} io_t;


static io_t gpios[] = {
//		{0, FUNC_GPIO0, PERIPHS_IO_MUX_GPIO0_U},

// debug tx
//		{2, FUNC_GPIO2, PERIPHS_IO_MUX_GPIO2_U},

		{4, FUNC_GPIO4, PERIPHS_IO_MUX_GPIO4_U},
		{5, FUNC_GPIO5, PERIPHS_IO_MUX_GPIO5_U},
// not working
//		{9, FUNC_GPIO9, PERIPHS_IO_MUX_SD_DATA2_U},
//		{10, FUNC_GPIO10, PERIPHS_IO_MUX_SD_DATA3_U},
		{12, FUNC_GPIO12, PERIPHS_IO_MUX_MTDI_U},
		{13, FUNC_GPIO13, PERIPHS_IO_MUX_MTCK_U},
		{14, FUNC_GPIO14, PERIPHS_IO_MUX_MTMS_U},
		{15, FUNC_GPIO15, PERIPHS_IO_MUX_MTDO_U}
	};

const int gpio_count = sizeof(gpios) / sizeof(*gpios);

void ICACHE_FLASH_ATTR set_gpio(int gpio_index, int ena)
{
	int i;
	for(i=0; i<gpio_count; i++) {
		io_t *p = gpios + i;
		if(p->n == gpio_index) {
			if (ena) {
				GPIO_OUTPUT_SET(GPIO_ID_PIN(gpio_index), 1);
			} else {
				GPIO_OUTPUT_SET(GPIO_ID_PIN(gpio_index), 0);
			}
			break;
		}
	}
}

int ICACHE_FLASH_ATTR get_gpio(int gpio_index)
{
	int rs = -1;
	int i;
	for(i=0; i<gpio_count; i++) {
		io_t *p = gpios + i;
		if(p->n == gpio_index) {
			rs = GPIO_INPUT_GET(GPIO_ID_PIN(gpio_index));
			break;
		}
	}
	return rs;
}

void ioInit() {
	int i;
	gpio_init();
	for(i=0; i< gpio_count; i++) {
		PIN_FUNC_SELECT(gpios[i].io_mux, gpios[i].io_id);
	//disable pulldown
//	PIN_PULLDWN_DIS(gpios[i].io_mux);
	//enable pull up R
//	PIN_PULLUP_DIS(gpios[i].io_mux;
	//1
//	GPIO_OUTPUT_SET(GPIO_ID_PIN(gpios[i].n, 1);
	}
}

