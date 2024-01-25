//spread op ...
//Allows spread out elements of an iterable object such as array, map, set
const odd = [1, 3, 5];
//...odd unpacks elements of odd array
const combined = [2, 4, 6, ...odd];
console.log("Combined array is: ", combined);
//spread operator can be anywhere
const combined2 = [...odd, 2, 4, 6];
console.log("Combined array is: ", combined2);
//can it be in the middle?
const combined3 = [2, 4, ...odd, 6];
console.log("Combined array is: ", combined3);
//spread can also be used with push 
const even = [2, 4, 6]
const newArr = [];
newArr.push(...even);
newArr.push(...odd);
console.log("newly pushed arr is: ", newArr);
const anotherArr = [...odd, ...even];
console.log("another array composed of: ", anotherArr);
//can create new array and add
const newlyArr = [...anotherArr, 0, 2, 4, 6, 7];

