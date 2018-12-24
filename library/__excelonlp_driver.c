/*
    __excelonlp_driver.c

-----------------------------------------------------------------------------

  This file is part of mikroSDK.

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

#include "__excelonlp_driver.h"
#include "__excelonlp_hal.c"

/* ------------------------------------------------------------------- MACROS */

/* OPCODE COMMANDS */
const uint8_t _EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH   = 0x06;
const uint8_t _EXCELONLP_OPCODE_RESET_WRITE_ENABLE_LATCH = 0x04;
const uint8_t _EXCELONLP_OPCODE_READ_STATUS_REGISTER     = 0x05;
const uint8_t _EXCELONLP_OPCODE_WRITE_STATUS_REGISTER    = 0x01;
const uint8_t _EXCELONLP_OPCODE_WRITE_MEMORY_DATA        = 0x02;
const uint8_t _EXCELONLP_OPCODE_READ_MEMORY_DATA         = 0x03;
const uint8_t _EXCELONLP_OPCODE_FAST_READ_MEMORY_DATA    = 0x0B;
const uint8_t _EXCELONLP_OPCODE_SPECIAL_SECTOR_WRITE     = 0x42;
const uint8_t _EXCELONLP_OPCODE_SPECIAL_SECTOR_READ      = 0x4B;
const uint8_t _EXCELONLP_OPCODE_READ_DEVICE_ID           = 0x9F;
const uint8_t _EXCELONLP_OPCODE_READ_UNIQUE_ID           = 0x4C;
const uint8_t _EXCELONLP_OPCODE_WRITE_SERIAL_NUMBER      = 0xC2;
const uint8_t _EXCELONLP_OPCODE_READ_SERIAL_NUMBER       = 0xC3;
const uint8_t _EXCELONLP_OPCODE_ENTER_DEEP_POWER_DOWN    = 0xBA;
const uint8_t _EXCELONLP_OPCODE_Enter_Hibernate_Mode     = 0xB9;



/* ---------------------------------------------------------------- VARIABLES */

#ifdef   __EXCELONLP_DRV_I2C__
static uint8_t _slaveAddress;
#endif

/* -------------------------------------------- PRIVATE FUNCTION DECLARATIONS */



/* --------------------------------------------- PRIVATE FUNCTION DEFINITIONS */



/* --------------------------------------------------------- PUBLIC FUNCTIONS */

#ifdef   __EXCELONLP_DRV_SPI__

void excelonlp_spiDriverInit(T_EXCELONLP_P gpioObj, T_EXCELONLP_P spiObj)
{
    hal_spiMap( (T_HAL_P)spiObj );
    hal_gpioMap( (T_HAL_P)gpioObj );

    hal_gpio_csSet(1);
    hal_gpio_pwmSet(1);
}

#endif
#ifdef   __EXCELONLP_DRV_I2C__

void excelonlp_i2cDriverInit(T_EXCELONLP_P gpioObj, T_EXCELONLP_P i2cObj, uint8_t slave)
{
    _slaveAddress = slave;
    hal_i2cMap( (T_HAL_P)i2cObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif
#ifdef   __EXCELONLP_DRV_UART__

void excelonlp_uartDriverInit(T_EXCELONLP_P gpioObj, T_EXCELONLP_P uartObj)
{
    hal_uartMap( (T_HAL_P)uartObj );
    hal_gpioMap( (T_HAL_P)gpioObj );
}

#endif

/* ----------------------------------------------------------- IMPLEMENTATION */

/**
 * @brief Functions for send opcode command
 *
 * @param[in] opcode    command to be sent
 */
void excelonlp_sendCommand(uint8_t opcode)
{
    uint8_t writeReg[1];
    
    writeReg[0] = opcode;
    
    hal_gpio_csSet(0);
    hal_spiWrite(writeReg,1);
    hal_gpio_csSet(1);
}
/**
 * @brief Functions for read data
 *
 * @param[in] opcode     Command to be sent
 * @param[out] OUTBuf    Buffer in which data will be storage
 * @param[in] nData      Number of bytes to be read
 */
void excelonlp_readData(uint8_t opcode, uint8_t *OUTBuf, uint8_t nData)
{
    hal_gpio_csSet(0);
    hal_spiWrite(&opcode,1);
    hal_spiRead(OUTBuf, nData);
    hal_gpio_csSet(1);
}

/**
 * @brief Functions for write data to memory
 *
 * @param[in] opcode     Command to be sent
 * @param[in] addr       addres in memmory
 * @param[in] _data      Data to be written
 */
void excelonlp_writeMemoryData(uint8_t opcode, uint32_t addr, uint8_t _data)
{
     uint8_t writeReg[5];
     
     writeReg[ 0 ] = opcode;
     writeReg[ 1 ] = (uint8_t)((addr >> 16) & 0x000000FF);
     writeReg[ 2 ] = (uint8_t)((addr >> 8) & 0x000000FF);
     writeReg[ 3 ] = (uint8_t)(addr & 0x000000FF);
     writeReg[ 4 ] = _data;
     
     hal_gpio_csSet(0);
     hal_spiWrite(writeReg, 5);
     hal_gpio_csSet(1);
}

/**
 * @brief Functions for read data form memory
 *
 * @param[in] opcode     Command to be sent
 * @param[in] addr       addres in memmory
 * @return Read data from the memory
 */
uint8_t excelonlp_readMemoryData(uint8_t opcode, uint32_t addr)
{
     uint8_t writeReg[5];
     uint8_t readReg[5];
     
     writeReg[ 0 ] = opcode;
     writeReg[ 1 ] = (uint8_t)((addr >> 16) & 0x000000FF);
     writeReg[ 2 ] = (uint8_t)((addr >> 8) & 0x000000FF);
     writeReg[ 3 ] = (uint8_t)(addr & 0x000000FF);

     hal_gpio_csSet(0);
     hal_spiTransfer(writeReg,readReg, 5);
     hal_gpio_csSet(1);
     
     return readReg[4];
}







/* -------------------------------------------------------------------------- */
/*
  __excelonlp_driver.c

  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. All advertising materials mentioning features or use of this software
   must display the following acknowledgement:
   This product includes software developed by the MikroElektonika.

4. Neither the name of the MikroElektonika nor the
   names of its contributors may be used to endorse or promote products
   derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY MIKROELEKTRONIKA ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL MIKROELEKTRONIKA BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

----------------------------------------------------------------------------- */