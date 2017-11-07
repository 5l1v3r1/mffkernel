/*
*  tty.c
*/

static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25;
static const char TTY_COLOR = 0x0A;

int col=0;
int row=0;

char *vidptr = (char*)0xb8000; 	//video mem begins here.

void cls() {
	unsigned int i = 0;
	unsigned int j = 0;
	/* this loops clears the screen
	* there are 25 lines each of 80 columns; each element takes 2 bytes */
	while(j < VGA_WIDTH * VGA_HEIGHT * 2) {
		/* blank character */
		vidptr[j] = ' ';
		/* attribute-byte - light grey on black screen */
		vidptr[j+1] = 0x07; 		
		j = j + 2;
	}
	//j = 0; 
}

void tty_put(x,y,c){
	int j = y * VGA_WIDTH + x;
	vidptr[j] = c;
	vidptr[j+1] = TTY_COLOR;
}

void tty_putchar(char c){
	tty_put(col,row,c);
	col = col + 2;
	if (col == VGA_WIDTH)
		col = 0;
		if (row == VGA_HEIGHT)
			row = 0;
}

void tty_print(char *str) {
	unsigned int j = 0;
	unsigned int i = 0;
	/* this loop writes the string to video memory */
	while(str[j] != '\0') {
		//j++;
		if (str[j] == '\n') {
			row = row +2;
		} else if ( str[j] == '\r') {
			col = 0;
		} else {
			tty_putchar(str[j]);
		}
		j++;
	}
}

unsigned long strlen(const char* str) {
	unsigned long len = 0;
	while (str[len])
		len++;
	return len;
}
