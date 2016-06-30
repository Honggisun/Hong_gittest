#include <stdio.h>
#include <stdlib.h>

void setColor(int fore_color,int backg_color)
{
	printf("%c[%d;%dm",0x1b,fore_color,backg_color);
}

void gotoxy(int x, int y)
{
	printf("%c[%d;%df",0x1b,y,x);
}

int main()
{
	int fore_color;
	fore_color = 31;
	system("clear");
	//"\x1b[31m"`
	//printf("%c[%dm",0x1b,fore_color);
	setColor(37,44);
	gotoxy(21,11);
	printf("                   ");
	setColor(37,44);
	gotoxy(21,12);
	printf("    BlueScreen     ");
	setColor(37,44);
	gotoxy(21,13);
	printf("                   ");
	setColor(37,44);
	gotoxy(21,14);
	printf("                   ");
	setColor(37,44);
	gotoxy(21,15);
	printf("   ~(=^_^)Goodbye~ ");
	setColor(37,44);
	gotoxy(21,19);
	printf("                   ");
	setColor(37,44);
	gotoxy(21,16);
	printf("                   ");
	setColor(37,44);
	gotoxy(21,17);
	printf("                   ");
	setColor(37,44);
	gotoxy(21,18);
	printf("                   ");
	setColor(37,44);
	gotoxy(21,19);
	printf("            Gisun  ");
	setColor(0,0); //reset ansi command
	
	gotoxy(21,11);
	setColor(31,41);
	printf("|");
	gotoxy(21,12);
	setColor(31,42);
	printf("|");
	gotoxy(21,13);
	setColor(31,43);
	printf("|");
	gotoxy(21,14);
	setColor(31,41);
	printf("|");
	gotoxy(21,15);
	setColor(31,45);
	printf("|");
	gotoxy(21,16);
	setColor(31,46);
	printf("|");
	gotoxy(21,17);
	setColor(31,47);
	printf("|");
	gotoxy(21,18);
	setColor(31,41);
	printf("|");
	gotoxy(21,19);
	setColor(31,42);
	printf("|");
	gotoxy(40,11);
	setColor(31,41);
	printf("|");
	gotoxy(40,12);
	setColor(31,45);
	printf("|");
	gotoxy(40,13);
	setColor(31,46);
	printf("|");
	gotoxy(40,14);
	setColor(31,47);
	printf("|");
	gotoxy(40,15);
	setColor(31,41);
	printf("|");
	gotoxy(40,16);
	setColor(31,42);
	printf("|");
	gotoxy(40,17);
	setColor(31,43);
	printf("|");
	gotoxy(40,18);
	setColor(31,41);
	printf("|");
	gotoxy(40,19);
	setColor(31,45);
	printf("|");
	setColor(32,47);
	gotoxy(21,10);
	printf("====================");
	setColor(32,47);
	gotoxy(21,20);
	printf("====================");
	setColor(32,47);
	gotoxy(27,21);
	printf("|     |");
	setColor(32,47);
	gotoxy(27,22);
	printf("|     |");
	setColor(32,47);
	gotoxy(21,23);
	printf("   ==============   ");
	setColor(0,0);
	return 0;
}
