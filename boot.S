#include <asm.h>
#include <vexpress.h>

	.section "vectors"
reset:  
	b start
undef: 
	b handle_abt
swi:     
	b  handle_abt
pabt:  
	b  handle_abt
dabt: 
	b  handle_abt
irq:   
	b  handle_abt
fiq:   
	b  handle_abt

	.text
.align 8

start:
	ldr r0, =START_ADDRESS
	
	mcr VBAR(r0)	
	ldr sp,=stackSVC
	bl print_mode
	
	cps  #MODE_UND
	ldr sp,=stackUND
	bl print_mode
	
	
	cps #MODE_ABT
	ldr sp,=stackABT
	bl print_mode
	
	cps #MODE_IRQ
	ldr sp,=stackIRQ
	bl print_mode
	
	cps #MODE_FIQ
	ldr sp,=stackFIQ
	bl print_mode
	
	cps #MODE_USR
	ldr sp,=stackUSR
	bl print_mode

	bl main

txt: .asciz "enter\n"
abt: .asciz "ABORT\n"
svc: .asciz "SVC\n"
usr: .asciz "USR\n"
iirq: .asciz "IRQ\n"
und: .asciz "UNDEF\n"

.align 4

print_mode:
	mrs r0,cpsr
	and r0,#0x1F
	mov r1,r0
	
	subs r3,r1,#MODE_ABT
	ldreq r0,=abt
	beq puts
	
	subs r3,r1,#MODE_SVC
	ldreq r0,=svc
	beq puts
	
	subs r3,r1,#MODE_USR
	ldreq r0,=usr
	beq puts

	subs r3,r1,#MODE_UND
	ldreq r0,=und
	beq puts
	
	subs r3,r1,#MODE_IRQ
	ldreq r0,=iirq
	beq puts
	
	mov pc,lr
	
handle_abt: 
	bl print_mode
stop:	b stop


			