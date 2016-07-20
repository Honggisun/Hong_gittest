/**
 * Created by KICT-12 on 2016-07-19.
 

let array_test = [1,2,3,4,5];

console.log(array_test);

array_test.reverse();
console.log(array_test); */
#include <stdio.h>
#include <string.h>

int main ()
{
int array[0] = [1,2,3,4,5];

for(int i=0;i<5;i++) {
	array[0] = array[i];
}


	return 0;
}
