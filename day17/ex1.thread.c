#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_t tid;

void *doSomeThing(void *arg)
{
	int nCount = 0;
	while(1)
	{
		printf("%d sec\r\n",nCount);
		//puts("test");
		sleep(1);
		nCount++;
	}
	return NULL;
}

int main()
{

	int err;
	err = pthread_create(&tid,NULL,&doSomeThing,NULL);
	if(err != 0) {
		printf("\r\n cannot created thread : [%s] \r\n",strerror(err));
	}
	else {
		printf("\r\n Thread created successfully \r\n");
	}
	
	char ch = getchar();

	//doSomeThing(NULL);

	printf("u press %c key \r\n",ch);


	return 0;
}

