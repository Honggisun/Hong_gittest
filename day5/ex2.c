#include <stdio.h>

int main()

{
	double a=1.3;
	double b=1.7;
	double temp;

	double *pa,*pb;

	printf("%f %f \r\n",a,b);

//	temp = a;
//	a = b;
//	b = temp;

	pa = &a;
	pb = &b;

	temp = *pa;
	*pa = *pb;
	*pb = temp;

	printf("%f %f \r\n",a,b);


	return 0;
}
