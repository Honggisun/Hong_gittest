/**
 * Created by KICT-12 on 2016-07-19.
 */

//char array_test[] = {1,2,3,4,5};
let array_test = [52,263,103,32,274];

for(let i=0;i< array_test.length;i++) {
    console.log(array_test[i]);
}
console.log('---------------------');
for(let index in array_test) {
    console.log(array_test[index]);
}