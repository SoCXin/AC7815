#--------------------------------- 编译参数 ------------------------------------
ifneq ($(V),1)
Q		:= @
NULL	:= 2>/dev/null
endif

TARGET := DEMO#编译文件名称，根据命名需要可自行修改
OPT    := -O0
CSTD   := -std=c11
CXXSTD := -std=c++11

#--------------工程需要编译的头文件，根据需要自行添加--------------------
INC_FLAGS += -I ./Device/Include     \
		     -I ./Device/Include/CMSIS \
			 -I ./Drivers/inc	
#------链接文件,里面指定了芯片flash,ram大小，需根据实际大小进行修改
LDSCRIPT := ./Device/Source/ARM/ac7811_flash.ld

ARCH_FLAGS += -mthumb
ARCH_FLAGS += -mcpu=cortex-m3


CWARN_FLAGS += -Wall -Wshadow
CWARN_FLAGS += -fno-common -ffunction-sections -fdata-sections
CWARN_FLAGS += -Wimplicit-function-declaration  
CWARN_FLAGS += -Wstrict-prototypes

#--通过printf打印串口log，需设置-specs=nosys.specs，并且在syscalls.c中实现_write_r函数，把printf映射到串口上。
LDLIBS		+= -Wl,--start-group -lc -lgcc  -Wl,--end-group -lm -specs=nosys.specs 


#----------------------------- 搜索工程目录下的源代码 ---------------------------

AS_SRC := ./Device/Source/ARM/startup_ac78xx.s
AS_OBJ := $(AS_SRC:%.s=%.o)
#-------源代码需根据实际情况删减-------------
C_SRC := ./Device/Source/ac78xx_ckgen.c    \
		 ./Device/Source/ac78xx_spm.c      \
		 ./Device/Source/system_ac78xx.c   \
		 ./Device/Source/ac78xx_debugout.c \
		 ./Device/Source/syscalls.c \
		 ./Drivers/src/ac78xx_dma.c	\
		 ./Drivers/src/ac78xx_gpio.c	\
		 ./Drivers/src/ac78xx_timer.c	\
		 ./Drivers/src/ac78xx_uart.c	\
		 ./Drivers/src/ac78xx_wdg.c	\
		 ./App/main.c
C_OBJ := $(C_SRC:%.c=%.o)  

#--------------------------------- 参数整合 ------------------------------------
# C flags
CFLAGS := $(OPT) $ $(CSTD) $(INC_FLAGS) $(FP_FLAGS) 
CFLAGS += $(DEFINES) $(ARCH_FLAGS) $(CWARN_FLAGS) -g

# Linker flags
LDFLAGS		:= --static
LDFLAGS		+= -Wl,-Map=$(TARGET).map -Wl,--gc-sections
LDFLAGS		+= -T$(LDSCRIPT) $(ARCH_FLAGS) $(LDLIBS)

# OBJ
OBJ = $(AS_OBJ) $(C_OBJ)

#-------------------------------- 编译器调用指令 --------------------------------
PREFIX	:= arm-none-eabi

CC		:= $(PREFIX)-gcc
CXX		:= $(PREFIX)-g++
LD		:= $(PREFIX)-gcc
AR		:= $(PREFIX)-ar
AS		:= $(PREFIX)-as
OBJCOPY	:= $(PREFIX)-objcopy
OBJDUMP	:= $(PREFIX)-objdump
GDB		:= $(PREFIX)-gdb


#----------------------------------- 编译对象 -----------------------------------
.SUFFIXES: .elf .bin .hex .list .map .images
.SECONDEXPANSION:
.SECONDARY:

all: elf bin hex

elf: $(TARGET).elf
bin: $(TARGET).bin
hex: $(TARGET).hex
list: $(TARGET).list
images: $(TARGET).images

%.images: %.bin %.hex %.list %.map
	@printf "*** $* images generated ***\n"
	
%.bin: %.elf          
	@printf "  OBJCOPY $(*).bin\n"
	$(Q)$(OBJCOPY) -Obinary $(*).elf $(*).bin
	
%.hex: %.elf
	@printf "  OBJCOPY $(*).hex\n"
	$(Q)$(OBJCOPY) -Oihex $(*).elf $(*).hex
	
%.list: %.elf
	@printf "  OBJDUMP $(*).list\n"
	$(Q)$(OBJDUMP) -S $(*).elf > $(*).list
	
%.elf %.map: $(OBJ) $(LDSCRIPT)
	@printf "  LD      $(TARGET).elf\n"
	$(Q)$(LD) $(OBJ) $(LDFLAGS) -o $(TARGET).elf
	
$(AS_OBJ): %.o:%.s
	@printf "  AS      $(*).s\n"
	$(Q)$(CC) $(ARCH_FLAGS) $(FP_FLAGS) -g -Wa,--no-warn -x assembler-with-cpp -o $(*).o -c $(*).s
	
$(C_OBJ): %.o:%.c
	@printf "  CC      $(*).c\n"
	$(Q)$(CC) $(CFLAGS) -o $(*).o -c $(*).c
	
clean:
	@#printf "  CLEAN\n"
	$(Q)$(RM) $(shell find -name '*.o' -o -name '*.d' -o -name '*.elf' -o -name '*.bin') 
	$(Q)$(RM) $(shell find -name '*.hex' -o -name '*.srec' -o -name '*.list' -o -name '*.map') 
	$(Q)$(RM) $(shell find -name 'generated.*' -o -name '*.srec' -o -name '*.list' -o -name '*.map') 

.PHONY: images clean elf bin hex list flash debug

