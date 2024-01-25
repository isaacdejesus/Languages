const arrayOfNums: number[] = [0, 1, 3,  5, 7];
const secondArrOfNums: number[] = [2, 4, 6, 8, 0];
//concat two arrays
const unionOfTwoArrays: number[] = arrayOfNums.concat(secondArrOfNums);
console.log(unionOfTwoArrays);
const logArrays = (array: number[]) => {
    array.forEach((element: number) => console.log(element));
    for(const element of array)
        console.log(element);
}
//get size of arr
console.log("length of array is: ", unionOfTwoArrays.length);
//includes()
console.log(unionOfTwoArrays.includes(0));
//indexOf() return index of first match
console.log("index of 7 is", unionOfTwoArrays.indexOf(7));
//logArrays(unionOfTwoArrays);
//join() returns a single string with contents of array
const stringOfArrays: string = unionOfTwoArrays.join('-');
console.log(stringOfArrays);
//last index of - returns index of last loc of a given element
console.log("Last index of 0 is: ", unionOfTwoArrays.lastIndexOf(0));
//pop() removes last element
//push() adds element to end
//reverse() Sort elements in descending order
console.log(unionOfTwoArrays.reverse());
//shift() remove first element
//unshift() add new element at beginning
//slice() copies portion of array into new array
const slicedArray: number[] = unionOfTwoArrays.slice(1,3);
console.log("Sliced array is: ", slicedArray);
//sort() sorts alphabetically
//toString(), converts elements to strings
const sortedIntoStrings = unionOfTwoArrays.sort().toString();
console.log(sortedIntoStrings);
