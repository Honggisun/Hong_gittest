#include <stdio.h>

int str_prn(char **ptr_ary,int count)
{
	int i;

	for(i=0;i<count;i++) {
		printf("%s \r\n", ptr_ary[i]);
	}
}

int main()
{
	char * ptr_ary[]={"eagle", "tiger", "lion", "squirrel"};

	int count;

	count = sizeof(ptr_ary)/sizeof(ptr_ary[0]);

	str_prn(ptr_ary,count);
	
	return 0;

	}
