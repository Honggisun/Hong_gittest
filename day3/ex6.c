#include <stdio.h>
#include <stdlib.h>
#include "../engine2d.h"

int main()
{
	int bLoop = 1;
	char cmd;
	int xpos,ypos;
	xpos =1;ypos=1;

	int orc_xpos,orc_ypos;
	orc_ypos = 10;
	orc_xpos = 10;

	while(bLoop) {
		scanf("%c",&cmd);
		switch(cmd) {
			case 'u':
				ypos -=1;
				break;
			case 'd':
				ypos +=1;
				break;
			case 'q':
				bLoop =0;
				break;		
			case 'l':
				xpos -=1;
				break;
			case 'r':
				xpos +=1;
				break;
		}

		system("clear");
		//주인공 출력
		drawMyBox(2+xpos,ypos,43,0);
		drawMyBox(xpos,1+ypos,43,1);
		drawMyBox(3+xpos,1+ypos,43,1);
		drawMyBox(1+xpos,1+ypos,44,2);
		drawMyBox(1+xpos,5+ypos,41,0);
		drawMyBox(3+xpos,5+ypos,41,0);
		drawMyBox(1+xpos,4+ypos,41,0);
		drawMyBox(3+xpos,4+ypos,41,0);
		//몹 AI
		if(orc_xpos > xpos) {
			orc_xpos -= 1;
		}
		else if(orc_xpos < xpos) {
			orc_xpos += 1;
		}
		else {

		}
		//몹 출력
		drawMyBox(orc_xpos,orc_ypos,42,2);
		gotoxy(0,20);
		printf("---------------------------");

		printf("%d,%d \r",xpos,ypos);		
	}

	return 0;
}

