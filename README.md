![MikroE](http://www.mikroe.com/img/designs/beta/logo_small.png)

---

# ExcelonLP Click

- **CIC Prefix**  : EXCELONLP
- **Author**      : Katarina Perenidc
- **Verison**     : 1.0.0
- **Date**        : avg 2018.

---

### Software Support

We provide a library for the ExcelonLP Click on our [LibStock](https://libstock.mikroe.com/projects/view/2535/excelon-lp-click) 
page, as well as a demo application (example), developed using MikroElektronika 
[compilers](http://shop.mikroe.com/compilers). The demo can run on all the main 
MikroElektronika [development boards](http://shop.mikroe.com/development-boards).

**Library Description**

The library initializes and defines the SPI bus driver and drivers that offer a choice for writing data in memory and reading data from memory.

Key functions :

- ``` void excelonlp_sendCommand(uint8_t opcode) ``` - Functions for send opcode command
- ``` void excelonlp_readData(uint8_t opcode, uint8_t *OUTBuf, uint8_t nData) ``` - Functions for read data
- ``` void excelonlp_writeMemoryData(uint8_t opcode, uint32_t addr, uint8_t _data) ``` - Functions for write data to memory
- ``` uint8_t excelonlp_readMemoryData(uint8_t opcode, uint32_t addr) ``` - Functions for read data form memory

**Examples Description**

The application is composed of three sections :

- System Initialization - Initializes SPI module and set CS and PWM pin as OUTPUT
- Application Initialization - Initializes Driver init
- Application Task - (code snippet) - Reads device ID, writes 6-bytes (MikroE) to memory and reads 6-bytes from memory


```.c
void applicationTask()
{
    mikrobus_logWrite("Read Device ID : ", _LOG_TEXT);
    excelonlp_sendCommand(_EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH);
    excelonlp_readData(_EXCELONLP_OPCODE_READ_DEVICE_ID, &OUTBuf[0], 9);
    for(cnt = 0; cnt < 9; cnt++)
    {
        IntToHex(OUTBuf[cnt], demoText);
        mikrobus_logWrite(" 0x", _LOG_TEXT);
        mikrobus_logWrite(demoText, _LOG_TEXT);
        Delay_100ms();
    }
    mikrobus_logWrite(" ", _LOG_LINE);

   mikrobus_logWrite("Write MikroE data.", _LOG_LINE);
   excelonlp_sendCommand(_EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH);
   for(cnt = 0; cnt < 6; cnt++)
   {
        excelonlp_sendCommand(_EXCELONLP_OPCODE_SET_WRITE_ENABLE_LATCH);
        excelonlp_writeMemoryData(_EXCELONLP_OPCODE_WRITE_MEMORY_DATA, memoryAddress++, sendBuffer[cnt]);
        Delay_100ms();
   }
   memoryAddress = 0x00000055;
   mikrobus_logWrite("Read memory data : ", _LOG_TEXT);
   for(cnt = 0; cnt < 6; cnt++)
   {
       MemoryData[0] = excelonlp_readMemoryData(_EXCELONLP_OPCODE_READ_MEMORY_DATA, memoryAddress++);
       mikrobus_logWrite(MemoryData, _LOG_TEXT);
       Delay_100ms();
   }
   Delay_ms( 5000 );
}

```

The full application code, and ready to use projects can be found on our 
[LibStock](https://libstock.mikroe.com/projects/view/2535/excelon-lp-click) page.

Other mikroE Libraries used in the example:

- SPI

**Additional notes and informations**

Depending on the development board you are using, you may need 
[USB UART click](http://shop.mikroe.com/usb-uart-click), 
[USB UART 2 Click](http://shop.mikroe.com/usb-uart-2-click) or 
[RS232 Click](http://shop.mikroe.com/rs232-click) to connect to your PC, for 
development systems with no UART to USB interface available on the board. The 
terminal available in all Mikroelektronika 
[compilers](http://shop.mikroe.com/compilers), or any other terminal application 
of your choice, can be used to read the message.

---
### Architectures Supported

#### mikroC

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroBasic

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

#### mikroPascal

| STM | KIN | CEC | MSP | TIVA | PIC | PIC32 | DSPIC | AVR | FT90x |
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
| x | x | x | x | x | x | x | x | x | x |

---
---
