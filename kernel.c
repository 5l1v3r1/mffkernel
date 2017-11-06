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

void kcheck_A20()
{
	const char *a20on = "A20 is enabled\n";
	const char *a20off = "A20 is disabled\n";

	if (check_A20() == 1) {
		kprint(a20on);
	} else { 
		kprint(a20off); 
	}
}


void kmain(void)
{
	const char *str = "My fucking first kernel\nDario Clavijo\n";
	cls();
	kprint(str);

	kcheck_A20();
	//enable_A20();

	return 0;
}
