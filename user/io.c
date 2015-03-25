
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
	int io_id;
	int io_mux;
} io_t;


static io_t gpios[GPIO_COUNT] = {
		{FUNC_GPIO0, PERIPHS_IO_MUX_GPIO0_U},
		{FUNC_GPIO2, PERIPHS_IO_MUX_GPIO2_U},
		{FUNC_GPIO4, PERIPHS_IO_MUX_GPIO4_U},
		{FUNC_GPIO5, PERIPHS_IO_MUX_GPIO5_U},
		{FUNC_GPIO12, PERIPHS_IO_MUX_MTDI_U},
		{FUNC_GPIO14, PERIPHS_IO_MUX_MTMS_U}
	};


void ICACHE_FLASH_ATTR set_gpio(int gpio_index, int ena)
{
	if(gpio_index >= 0 && gpio_index < GPIO_COUNT) {
		if (ena) {
			gpio_output_set((1<<gpios[gpio_index].io_id), 0, (1<<gpios[gpio_index].io_id), 0);
		} else {
			gpio_output_set(0, (1<<gpios[gpio_index].io_id), (1<<gpios[gpio_index].io_id), 0);
		}
	}
}

int ICACHE_FLASH_ATTR get_gpio(int gpio_index)
{
	int rs = -1;
	if(gpio_index >= 0 && gpio_index < GPIO_COUNT) {
		rs = GPIO_INPUT_GET(gpios[gpio_index].io_id);
	}
	return rs;
}

void ioInit() {
	int i;
	gpio_init();
	for(i=0; i< GPIO_COUNT; i++) {
		PIN_FUNC_SELECT(gpios[i].io_mux, gpios[i].io_id);
	}
}

