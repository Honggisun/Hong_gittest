/**
 * Created by KICT-10 on 2016-07-19.
 */

let array_test = [
    {
        name : 'hi',
        hp : 52
    },
    {
        name: 'hello',
        hp: 27
    },
    {
        name : 'world',
        hp :37
    },
    {
        name : 'gisun',
        hp : 100
    }
]
console.log(array_test);

array_test.sort();

array_test.sort((left,right) => {
  //  return left.hp - right.hp;
    return right.hp - left.hp;
})
console.log('--------------------------------------');
console.log(array_test);