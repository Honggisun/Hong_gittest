#include <stdio.h>

int main()
{
	char cmd;
	scanf("%c",&cmd);
	/*
	if(cmd  =='z') {
		printf("질럿을 생산합니다.\r\n");
	}
	else if(cmd == 'd'){
		printf("드라군을 생산합니다.\r\n");
	}
	else {
		printf("잘못된 입력입니다.\r\n");
	}
	*/
	switch(cmd) {
		case 'c':
		printf("캐리어를 생산합니다.\r\n");
		break;

		case 'z': 
		printf("질럿을 생산합니다.\r\n");
		break;
		
		case 'd':
		printf("드라군을 생산합니다.\r\n");
		break;
		
		default:
		printf("잘못된 입력입니다.\r\n");
		break;
	}
	return 0;
}
