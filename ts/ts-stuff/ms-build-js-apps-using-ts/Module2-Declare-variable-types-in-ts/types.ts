//type inference
let x: number;  //explicitly declares x as number type
let y = 1;      //Implicitly declares y as number type
let z;          //Declares z without ini

//NOTE: Both x and y are of type number. Compiler inferred y to be of type number
//Trying to set y to anything other than a number will cause errors. 
//z on the other hand can be set to anything since it was never initialzed
//However once ini, for ex, z = 'hello', it will become type string
//Therefore, it isn't necessary to explicitly type a variable bc compiler will
//infer type based on value given to it. 



//primite types
//boolean
let flag: boolean;
let yes = true;
let no = false;

//number and bigint types
let x1: number;
let y1 = 0;
let z1: number = 123.456;
//let big: bigint = 100n;

//string type
let s: string;
let empty = "";
let abc = 'abc';
let first_name: string = "isaac";
let intro: string = `My name is ${first_name}. I am new to Typescript.`;
console.log(intro);

//null and undefined mostly used when dealing with functions

//enum
enum contract_status {
    Permanent,   //maps to 0
    Temp,        //maps to 1
    Apprentice   //maps to 2
}
let employee_status: contract_status = contract_status.Temp;
console.log(employee_status);  //1
//Enum values being with 0 .:.
//Permanent is 0
//Temp is 1
//Apprentice is 2

//Can set enum values to start a custom values. Ex. start at 1
enum contract_status_1 {
    Permanent = 1,   //maps to 1
    Temp,            //maps to 2
    Apprentice       //maps to 3
}

//to display/obtain value associated with enuma value
console.log(contract_status[employee_status]);  //Temp

//any 
//usewhen values are unknown 
let random_value: any = 10;
//any types have access to all methods be it number, string, etc
//any type won't cause compiler errors


//unknown
//similar to any expect won't allow you to use all methods and can't interact with var of type unknown
//code won't compile unless unknown type is resolved


//type assertion
//allow to treat a var as a different data type .:. allowing to use that data type's methods
//2 days to use type assertion
// (var as string).toUpperCase();
// (<string>var).toUpperCase();
let random_var:unknown = 10;
random_var = true;
random_var = 'Hello';
if(typeof random_var === "string")
    console.log((random_var as string).toUpperCase());  // tells compiler to treat var as string
else
    console.log("Error - A string was expected");
//type guards
//See above, usage of typeof with if conditional test is a type guard
