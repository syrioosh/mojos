CC=$(TOOLCHAIN_PREFIX)gcc
LD=$(TOOLCHAIN_PREFIX)ld
INC=$(PWD)/include/
LDFLAGS = -T mojos.lds 
ASFLAGS = -I$(INC)
CFLAGS =  -ggdb  -Wl,--build-id=none -march=armv7-a -mcpu=cortex-a9 -nostdlib --no-builtin -Wall -I$(INC) 
DEPS = vexpress.h

objs= \
	boot.o \
	main.o \
	uart.o \
	timer.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)  
	
mojOS: $(objs)
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)
clean:
	rm $(objs)
	rm mojOS
