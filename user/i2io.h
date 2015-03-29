#include <c_types.h>
#include "osapi.h"

void ICACHE_FLASH_ATTR i2io_init();
bool ICACHE_FLASH_ATTR i2c_read(uint8 addr, uint8 *pData, uint16 len);

