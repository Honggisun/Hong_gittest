#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	//add 10,20
	//sub 5,2
	//mul 4,3
	//div 8,2
	
	char strCmd[128];
	
	printf("add,sub,mul,div중 하나를 입력하세요\r\n");
	
	gets(strCmd);

	char *ptrTemp;
	char *pCmd;
	int a,b;

	ptrTemp = strtok(strCmd," ");
	
	pCmd = strdup(ptrTemp);

	//ptrTemp = strtok(NULL," ");
	
	a = atoi( strtok(NULL,",")) ;
	b = atoi( strtok(NULL,",")) ;


	//printf("%s \r\n",ptrTemp);

	if(strcmp(pCmd,"add") == 0) {
		printf("덧셈을 했다. 답은 %d \r\n",a+b);
	}
	else if(strcmp(pCmd,"sub") == 0) {
		printf("뺄셈을 했다. 답은 %d \r\n",a-b);
	}
	else if(strcmp(pCmd,"mul") == 0) {
		printf("곱셈을 했다. 답은 %d \r\n",a*b);
	}
	else if(strcmp(pCmd,"div")== 0) {
		printf("나누기를 했다. 답은 %d \r\n",a/b);
	}


	return 0;
}
