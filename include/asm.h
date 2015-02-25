#ifndef ASM_H
#define ASM_H

#define _write(a,v)        (*(volatile unsigned int *)(a) = (v))
#define VBAR(r)         p15, 0, r, c12, c0, 0


#endif // ASM_H
