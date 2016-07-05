#include <stdio.h>

int main()
{
	int a;
	a = 7;
	{
		int a;
		a = 3;
		{
			int a;
			a = 2;
			printf("%d \r\n",a);
		}
		printf("%d \r\n",a);
	}
	printf("%d \r\n",a);
}
