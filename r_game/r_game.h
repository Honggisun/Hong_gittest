#ifndef __RGAME_H__
#define __RGAME_H__

void drawGame(int mx,int my, char *pBuf)

{
	//랜더링 
	gotoxy(1,1);
	int x,y;
	for(y=0;y<my;y++)
	{
		for(x=0;x<my;x++) {
			switch( pBuf[mx*y+x]) {
				case 0:
				setColor(0,43);
					putchar('.');
					break;
				case 1:
				setColor(34,47);
					putchar('#');
					break;
				case 2:
				setColor(30,41);
					putchar('A');
					break;
			}
					setColor(0,0);
	
		}
		printf("\r\n");
	}
}

#endif
