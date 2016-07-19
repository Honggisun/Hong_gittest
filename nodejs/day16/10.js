/**
 * Created by KICT-10 on 2016-07-19.
 */

let array_test = ['banana','orange','apple','mango','rasberry'];
console.log(array_test);
array_test.splice(
    2, //삽입위치
    2, //삭제 원소 갯수
    "grape","peanut");
console.log(array_test);

array_test.splice(2,1);
console.log(array_test);