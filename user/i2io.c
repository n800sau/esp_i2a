#include "i2io.h"
#include <driver/i2c_master.h>
#include "user_interface.h"
#include "espmissingincludes.h"

bool ICACHE_FLASH_ATTR i2c_read(uint8 addr, uint8 *pData, uint16 len)
{
	uint8 ack;
	uint16 i;

	i2c_master_start();
	i2c_master_writeByte(addr);
	ack = i2c_master_getAck();

	if (ack) {
		os_printf("addr not ack when tx write cmd \n");
		i2c_master_stop();
		return false;
	}

	i2c_master_stop();
	i2c_master_wait(40000);

	i2c_master_start();
	i2c_master_writeByte(addr + 1);
	ack = i2c_master_getAck();

	if (ack) {
		os_printf("addr not ack when tx write cmd \n");
		i2c_master_stop();
		return false;
	}

	for (i = 0; i < len; i++) {
		pData[i] = i2c_master_readByte();

		i2c_master_setAck((i == (len - 1)) ? 1 : 0);
	}


	i2c_master_stop();

	return true;
}

void ICACHE_FLASH_ATTR i2io_init()
{
	i2c_master_gpio_init();
}
