#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"

int main()
{
	system("clear");

	int a=1;
	setColor(37,41);
	/*while(a<10) {
		gotoxy(5,a);
		printf("+");
		gotoxy(a,5);
		printf("+");
		a++;
	}*/
	while(a<10) {
		gotoxy(a,a);
		printf("+");
		gotoxy(10-a,a);
		printf("+");
		a++;
	}



	setColor(0,0);
	gotoxy(0,20);
	printf("================================================");
	return 0;
}
