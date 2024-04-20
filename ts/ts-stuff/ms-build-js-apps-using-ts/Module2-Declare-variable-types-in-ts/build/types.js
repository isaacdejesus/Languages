"use strict";
//type inference
let x; //explicitly declares x as number type
let y = 1; //Implicitly declares y as number type
let z; //Declares z without ini
//NOTE: Both x and y are of type number. Compiler inferred y to be of type number
//Trying to set y to anything other than a number will cause errors. 
//z on the other hand can be set to anything since it was never initialzed
//However once ini, for ex, z = 'hello', it will become type string
//Therefore, it isn't necessary to explicitly type a variable bc compiler will
//infer type based on value given to it. 
//primite types
//boolean
let flag;
let yes = true;
let no = false;
//number and bigint types
let x1;
let y1 = 0;
let z1 = 123.456;
//let big: bigint = 100n;
//string type
let s;
let empty = "";
let abc = 'abc';
let first_name = "isaac";
let intro = `My name is ${first_name}. I am new to Typescript.`;
console.log(intro);
