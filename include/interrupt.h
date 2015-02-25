#ifndef INTERRUPT_H
#define INTERRUPT_H

#include <vexpress.h>



#define ICDDCR 0
#define ICDICTR 4
#define ICDIIDR 8
#define ICDISR	0x80	// n
#define ICDISER 0x100	//(n)
#define ICDCER 0x180	//(n)
#define ICDISPR 0x200	//(n)
#define ICDICRP 0x280	//(n)
#define ICDABR 0x300	//(n)
#define ICDIPR 0x400	//(n)
#define ICDIPTR 0x800	//(n)
#define ICDICFR 0xC00
#define ICPPISR 0xD00


#define ICCICR 0
#define ICCPMR 4
#define ICCBPR 0x8
#define ICCIAR 0xC
#define ICCEOIR 0x10
#define ICCRPR 0x14
#define ICCIDR 0xFC



#define gic_icidser(nr) *((unsigned long *) (GIC_DISTRIBUTOR + (ICDISER + (nr/32)*4))) |= (1 << (nr % 32))
#define gic_icdiptr(nr,cpu) *((unsigned long *) (GIC_DISTRIBUTOR + (ICDIPTR + (nr/4)*4) + (nr%4))) |= cpu
#endif // INTERRUPT_H
