const aString: string = "I am a string";
console.log(aString);
//chatAt() returns chat at index
console.log("char at index 0 is: ", aString.charAt(0));
//concat() concats strings
//indexOf() returns index of first occurrence of given char
console.log("Index of 'a' is: ", aString.indexOf('a'));
//lastIndexOf() returns index of last occurrence of a given char
console.log("Index of last occurrence of 'a' is: ", aString.lastIndexOf('a'));
//match returns an array with info regarding matches found in string
console.log("matching: ", aString.match('am'));
//replace() find and replace text in string
const aNewString: string = aString.replace("string", "the great potato man!");
console.log(aNewString);
//search() returns index 
console.log("Potato is located at index: ", aNewString.search("potato"));
//slice() returns a new string with sliced content
const potato: string = aNewString.slice(17, 23);
console.log(potato);
//substr() returns a new string with sliced content using char count
const potato2: string = aNewString.substr(17,6);
console.log(potato2);
//substring() like substr() but doesnt accept neg indexes
const potato3: string = aNewString.substr(17,6);
console.log(potato3);
//split() splits string into array of string at given index
//returns array with instances of 'a' removed
const splitString = aNewString.split('a');
console.log(splitString);
console.log(aNewString);
//toLowerCase() and toUpperCase()
