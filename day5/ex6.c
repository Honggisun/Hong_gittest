#include <stdio.h>

int main()
{
	int num[] = {3,7,15,6,8,2};

	printf("배열의 갯수는 : %d \r\n",sizeof(num)/sizeof(int));
	
	int sum = 0;
	int max = -9999999;
	int min = 9999999;

	for(int i=0;i< sizeof(num)/sizeof(int);i++) {
		//sum = sum + num[i];
		sum += num[i];
		if(max < num[i]) {
			max = num[i];
		}
		if(min > num[i]) {
			min = num[i];
		}
	}

	printf("배열의 합은 : %d \r\n",sum);
	printf("배열의 최대값 : %d \r\n",max);
	printf("배열의 최소값 : %d \r\n",min);

	return 0;
}
	
