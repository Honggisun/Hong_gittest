#include <stdio.h>

int main()
{
	char aStr[] = "world";
	char *pStr = "hello";

	printf("%s %s \r\n",aStr,pStr);

	pStr = aStr; //O 

	printf("%s \r\n",pStr);

	//aStr = pStr; X

}
