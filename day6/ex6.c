#include <stdio.h>
#include <string.h>

int main()
{
	char *pStrCmd = "move position 123,56";

	char *ptr = strstr(pStrCmd,"location");

	printf("%s \r\n",ptr);

	char pStrTemp[128];

	strncpy(pStrTemp,pStrCmd,4);

	printf("%s \r\n",pStrTemp);

	char *pStrClone;
//	char pStrClone[128];

	pStrClone = strdup(pStrCmd);

	pStrClone[0] = 'a';
//	pStrClone = pStrCmd;

//	pStrCmd[0] = 'n';

	printf("%s \r\n",pStrClone);
	printf("%s \r\n",pStrCmd);

	return 0;
}
