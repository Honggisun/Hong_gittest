#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <sys/select.h>
#include <termios.h>

#include "../engine/engine2d.h"

char screen_buffer[8*8];

int car_posx,car_posy;

int main()
{
	//버퍼초기화 
	for(int i=0;i<64;i++) {
		screen_buffer[i] = 0;
	}

	struct timespec work_timer;
	set_conio_terminal_mode();
	
	int bLoop = 1;
	double acc_tick,last_tick;
	acc_tick = last_tick = 0;
	system("clear");

	car_posy = 7;
	car_posx = 3;

	while(bLoop) {

		//타이밍처리 
		clock_gettime(CLOCK_MONOTONIC,&work_timer);
		double cur_tick = work_timer.tv_sec + 
			(double)(work_timer.tv_nsec * 1e-9);
		double delta_tick = cur_tick - last_tick;
		last_tick = cur_tick;

		if(kbhit() != 0) {
			char ch = getch();
			if(ch == 'q') {
				bLoop = 0;
			}
			else if(ch == 'a') {
				car_posx -= 1;
			}
			else if(ch == 'd') {
				car_posx += 1;
			}
			//printf("%d \r\n",ch);
			
			
		}
		//버퍼초기화 
		for(int i=0;i<64;i++) {
			screen_buffer[i] = 0;
		}
		screen_buffer[ car_posy *8+ car_posx] = 2;

		acc_tick += delta_tick;
		if(acc_tick > 0.1) {
			acc_tick = 0;

			//랜더링 
			gotoxy(1,1);
			int x,y;
			for(y=0;y<8;y++)
			{
				for(x=0;x<8;x++) {
					switch( screen_buffer[8*y+x]) {
						case 0:
							putchar('.');
							break;
						case 1:
							putchar('#');
							break;
						case 2:
							putchar('A');
							break;
					}
				}
				printf("\r\n");
			}
		}

	}



	return 0;
}
