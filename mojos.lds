SECTIONS
{
. = 0x60000000;
.text : {
	. = ALIGN(4);
	*(vectors);
	. = ALIGN(4);
	*(.text);
	. = ALIGN(4);
}
.rodata : {
	* (.rodata);
}
.data : {
	*(.data);
}

.bss : {
	. = ALIGN(4);
	*(.bss);
}
.stack : {
	statckSTART = .;
	. = . + 0x0001000;
	. = ALIGN(4);
	stackSVC = .;
	
	. = . + 0x00001000;
	. = ALIGN(4);
	stackUND = .;
	
	. = . + 0x00001000;
	. = ALIGN(4);
	stackABT = .;
	
	. = . + 0x00001000;
	. = ALIGN(4);
	stackIRQ = .;
	
	. = . + 0x00001000;
	. = ALIGN(4);
	stackFIQ = .;	
	
	. = . + 0x00001000;
	. = ALIGN(4);
	stackUSR = .;
	
	stack_end = .;
	
}



}
