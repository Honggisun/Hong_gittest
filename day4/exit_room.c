#include <stdio.h>
#include <stdlib.h>
#include "engine2d.h"
#include "exit_room.h"

/*
 *
 1 : 벽 #
 2:  열린문 M
 3 : 게임머 A
 4: 잠긴문 m
 5: 키 K
 */

int world_map[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,1,0,0,0,1,
	1,0,0,1,0,0,0,1,
	1,0,5,1,0,0,0,1,
	4,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,1,1,1,1,1,1,1
};

int world_map2[] = {
	1,1,1,1,1,1,1,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,0,0,0,0,0,1,
	1,0,5,0,1,0,0,1,
	1,0,0,0,1,0,0,1,
	1,0,0,0,1,0,0,1,
	1,4,1,1,1,1,1,1
};

int game_version = 1;
char *game_name = "방탈출 게임"; 


int main()
{
	char cmd;
	int bLoop = 1;

	while(bLoop) {
		switch(nFSM) {
			case 0:
				printf("%s의 세계에 오신걸 환영합니다. V. %d \r\n ",game_name,game_version );
				printf("select => [p,x] \r\n");
				break;
			case 1:
				printf("명령을 선택하세요,\r\n \
						i(up),j(left),k(right),\r\n \
						m(down),s(show map),x(exit)\r\n");
				break;
			case 2:
				break;
			case 3:
				printf("명령을 선택하세요,\r\n \
						i(up),j(left),k(right),\r\n \
						m(down),s(show map),x(exit)\r\n");
				break;
		
		}

		//버퍼초기화
		for(int i=0;i<64;i++) {
			buffer_map[i] = world_map[i];
				}

		scanf("%c",&cmd);
		getchar();
		if(nFSM == 0) {
			switch(cmd) {
				case 'p': //게임스타트
					nFSM = 1;
					player_ypos = 5;
					player_xpos = 1;
					player_inven = 0;
					printf("게임을 시작합니다.");
					break;
				case 'x':
					bLoop = 0;
					printf("bye \r\n");
					break;
			}

		}
		else if(nFSM == 1 ) { //게임플레이 중일때..
			move_player(cmd);
			switch(cmd) {
				case 's':
					map_drawAll(buffer_map);
					break;
				case 'x':
					bLoop = 0;
					printf("bye bye~\r\n"); 
					break;
			}
		}
		for(int i=0;i<64;i++) {
			buffer_map2[i] = world_map2[i];
			}
			if(nFSM == 3 ) { //게임플레이 중일때..
			move_player2(cmd);
			switch(cmd) {
				case 's':
					map_drawAll(buffer_map2);
					break;
				case 'x':
					bLoop = 0;
					printf("bye bye~\r\n"); 
					break;
			}
		}
else if(nFSM == 2) {
			nFSM = 0;

		}
		
	}


	return 0;
}
