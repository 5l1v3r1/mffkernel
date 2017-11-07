/*
*  kernel.c
*/

void disable_ints();
void enable_ints();
int check_A20();
void enable_A20();
void cls();
void kprint(char *str); 
unsigned long strlen(const char* str);
char getScancode();

void kcheck_A20()
{
	if (check_A20() == 1) {
		tty_print("A20 is enabled\n\r");
	} else { 
		tty_print("A20 is disabled\n\r"); 
	}
}

void kspin(int spinCount){
	for (int i = 0; i < spinCount; ++i)
   		((void)0);  
}

void kmain(void)
{
	cls();
	tty_print("My fucking first kernel\n\rAutor: Dario Clavijo\n\r");

	kcheck_A20();
	//enable_A20();
	//gateA20();
	//kcheck_A20();

	tty_print("Spining...");
	while (1){
		kspin(1000);		
		//tty_putchar(getScancode);
	}
	tty_print("End of the spinning..."); //it never should reach this point
	return 0;
}
