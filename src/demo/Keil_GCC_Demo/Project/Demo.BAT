SET CPU_TYPE=AC7811OBGE
SET CPU_VENDOR=AutoChips
SET UV2_TARGET=Demo
SET CPU_CLOCK=0x00B71B00
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\ac78xx_ckgen.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\ac78xx_debugout.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\ac78xx_spm.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\system_ac78xx.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\syscalls.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-as" @".\objects\startup_ac78xx._ia"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\ac78xx_dma.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\ac78xx_gpio.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\ac78xx_timer.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\ac78xx_uart.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\ac78xx_wdg.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\objects\main.__i"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-gcc" @".\Objects\demo.lnp"
"C:\Program Files (x86)\GNU Tools ARM Embedded\7 2017-q4-major\bin\arm-none-eabi-objcopy.exe" -O ihex ./Objects/demo.elf ./Objects/demo.hex
.\Objects\hex2bin.exe .\Objects\demo.hex
