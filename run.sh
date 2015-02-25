#!/bin/bash
if [ $1 = "debug" ]
then
	qemu-system-arm -M vexpress-a9 -m  128   -serial stdio -kernel  mojOS -S -s
else 
	qemu-system-arm -M vexpress-a9 -m  128   -serial stdio -kernel  mojOS
fi

