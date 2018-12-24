/*
    __excelonlp_driver.h

-----------------------------------------------------------------------------

  This file is part of mikroSDK.
  
  Copyright (c) 2017, MikroElektonika - http://www.mikroe.com

  All rights reserved.

----------------------------------------------------------------------------- */

/**
@file   __excelonlp_driver.h
@brief    ExcelonLP Driver
@mainpage ExcelonLP Click
@{

@image html libstock_fb_view.jpg

@}

@defgroup   EXCELONLP
@brief      ExcelonLP Click Driver
@{

| Global Library Prefix | **EXCELONLP** |
|:---------------------:|:-----------------:|
| Version               | **1.0.0**    |
| Date                  | **avg 2018.**      |
| Developer             | **Katarina Perenidc**     |

*/
/* -------------------------------------------------------------------------- */

#include "stdint.h"

#ifndef _EXCELONLP_H_
#define _EXCELONLP_H_

/** 
 * @macro T_EXCELONLP_P
 * @brief Driver Abstract type 
 */
#define T_EXCELONLP_P    const uint8_t*

/** @defgroup EXCELONLP_COMPILE Compilation Config */              /** @{ */

   #define   __EXCELONLP_DRV_SPI__                            /**<     @macro __EXCELONLP_DRV_SPI__  @brief SPI driver selector */
//  #define   __EXCELONLP_DRV_I2C__                            /**<     @macro __EXCELONLP_DRV_I2C__  @brief I2C driver selector */                                          
// #define   __EXCELONLP_DRV_UART__                           /**<     @macro __EXCELONLP_DRV_UART__ @brief UART driver selector */ 

                                                                       /** @} */
/** @defgroup EXCELONLP_VAR Variables */                           /** @{ */

/* OPCODE COMMANDS */
extern const uint8_t _EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH  ;
extern const uint8_t _EXCELONLP_OPCODE_RESET_WRITE_ENABLE_LATCH;
extern const uint8_t _EXCELONLP_OPCODE_READ_STATUS_REGISTER    ;
extern const uint8_t _EXCELONLP_OPCODE_WRITE_STATUS_REGISTER   ;
extern const uint8_t _EXCELONLP_OPCODE_WRITE_MEMORY_DATA       ;
extern const uint8_t _EXCELONLP_OPCODE_READ_MEMORY_DATA        ;
extern const uint8_t _EXCELONLP_OPCODE_FAST_READ_MEMORY_DATA   ;
extern const uint8_t _EXCELONLP_OPCODE_SPECIAL_SECTOR_WRITE    ;
extern const uint8_t _EXCELONLP_OPCODE_SPECIAL_SECTOR_READ     ;
extern const uint8_t _EXCELONLP_OPCODE_READ_DEVICE_ID          ;
extern const uint8_t _EXCELONLP_OPCODE_READ_UNIQUE_ID          ;
extern const uint8_t _EXCELONLP_OPCODE_WRITE_SERIAL_NUMBER     ;
extern const uint8_t _EXCELONLP_OPCODE_READ_SERIAL_NUMBER      ;
extern const uint8_t _EXCELONLP_OPCODE_ENTER_DEEP_POWER_DOWN   ;
extern const uint8_t _EXCELONLP_OPCODE_Enter_Hibernate_Mode    ;

                                                                       /** @} */

#ifdef __cplusplus
extern "C"{
#endif

/** @defgroup EXCELONLP_INIT Driver Initialization */              /** @{ */

#ifdef   __EXCELONLP_DRV_SPI__
void excelonlp_spiDriverInit(T_EXCELONLP_P gpioObj, T_EXCELONLP_P spiObj);
#endif
#ifdef   __EXCELONLP_DRV_I2C__
void excelonlp_i2cDriverInit(T_EXCELONLP_P gpioObj, T_EXCELONLP_P i2cObj, uint8_t slave);
#endif
#ifdef   __EXCELONLP_DRV_UART__
void excelonlp_uartDriverInit(T_EXCELONLP_P gpioObj, T_EXCELONLP_P uartObj);
#endif

// GPIO Only Drivers - remove in other cases
void excelonlp_gpioDriverInit(T_EXCELONLP_P gpioObj);
                                                                       /** @} */
/** @defgroup EXCELONLP_FUNC Driver Functions */                   /** @{ */

void excelonlp_sendCommand(uint8_t opcode);
void excelonlp_readData(uint8_t opcode, uint8_t *OUTBuf, uint8_t nData);
void excelonlp_writeMemoryData(uint8_t opcode, uint32_t addr, uint8_t _data);
uint8_t excelonlp_readMemoryData(uint8_t opcode, uint32_t addr);





                                                                       /** @} */
#ifdef __cplusplus
} // extern "C"
#endif
#endif

/**
    @example Click_ExcelonLP_STM.c
    @example Click_ExcelonLP_TIVA.c
    @example Click_ExcelonLP_CEC.c
    @example Click_ExcelonLP_KINETIS.c
    @example Click_ExcelonLP_MSP.c
    @example Click_ExcelonLP_PIC.c
    @example Click_ExcelonLP_PIC32.c
    @example Click_ExcelonLP_DSPIC.c
    @example Click_ExcelonLP_AVR.c
    @example Click_ExcelonLP_FT90x.c
    @example Click_ExcelonLP_STM.mbas
    @example Click_ExcelonLP_TIVA.mbas
    @example Click_ExcelonLP_CEC.mbas
    @example Click_ExcelonLP_KINETIS.mbas
    @example Click_ExcelonLP_MSP.mbas
    @example Click_ExcelonLP_PIC.mbas
    @example Click_ExcelonLP_PIC32.mbas
    @example Click_ExcelonLP_DSPIC.mbas
    @example Click_ExcelonLP_AVR.mbas
    @example Click_ExcelonLP_FT90x.mbas
    @example Click_ExcelonLP_STM.mpas
    @example Click_ExcelonLP_TIVA.mpas
    @example Click_ExcelonLP_CEC.mpas
    @example Click_ExcelonLP_KINETIS.mpas
    @example Click_ExcelonLP_MSP.mpas
    @example Click_ExcelonLP_PIC.mpas
    @example Click_ExcelonLP_PIC32.mpas
    @example Click_ExcelonLP_DSPIC.mpas
    @example Click_ExcelonLP_AVR.mpas
    @example Click_ExcelonLP_FT90x.mpas
*/                                                                     /** @} */
/* -------------------------------------------------------------------------- */
/*
  __excelonlp_driver.h

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