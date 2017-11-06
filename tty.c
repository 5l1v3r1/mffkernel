/*
*  tty.c
*/

char *vidptr = (char*)0xb8000; 	//video mem begins here.

void cls() {
	unsigned int i = 0;
	unsigned int j = 0;
	/* this loops clears the screen
	* there are 25 lines each of 80 columns; each element takes 2 bytes */
	while(j < 80 * 25 * 2) {
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte - light grey on black screen */
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}
	j = 0; 
}

void kprint(char *str) {
	unsigned int j = 0;
	unsigned int i = 0;
	/* this loop writes the string to video memory */
	while(str[j] != '\0') {
		/* the character's ascii */
		vidptr[i] = str[j];
		/* attribute-byte: give character black bg and light grey fg */
		vidptr[i+1] = 0x0A;
		++j;
		i = i + 2;
	}
}

unsigned long strlen(const char* str) {
	unsigned long len = 0;
	while (str[len])
		len++;
	return len;
}
