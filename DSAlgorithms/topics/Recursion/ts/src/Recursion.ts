const numberInLine = (num: number): number => {
    if(num <= 1)
        return 1;
    return numberInLine(num - 1) + 1;
}

const sumOfNumbers = (n: number): number => {
    if(n <= 1)
        return 1;
    return sumOfNumbers(n - 1) + n;
}

const stringReversal = (input: string): string => {
    if(input.length === 0)
        return "";

    return stringReversal(input.substring(1)) + input[0];
}

const isPalindrome = (input: string): boolean => {
    if(input.length === 0 || input.length === 1)
        return true;
    if(input[0] === input[input.length - 1])
        return isPalindrome(input.substring(1, input.length - 1));
    return false;
}
const binarySearch = (Arr: number[], left: number, right: number, x: number): number => {
    if(left > right)
        return -1;
    let mid = Math.floor((left + right) / 2);
    if(x === Arr[mid])
        return mid;
    if(x < Arr[mid])
        return binarySearch(Arr, left, mid - 1, x);
    return binarySearch(Arr, mid + 1, right, x);
}
const sortedArr = [-1, 0, 3, 5, 7, 9, 11, 15];
console.log(numberInLine(5));
console.log(sumOfNumbers(5));
console.log(stringReversal("hello"));
console.log(isPalindrome("sarah"));
console.log(isPalindrome("hannah"));
console.log(binarySearch(sortedArr,0, 7, 11));
