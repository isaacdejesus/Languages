# hello world
- node.js javascript is compiled `node file.js`
### script tag
- Javascript can be embedded anywhere into HTML using `<script>` tag
```
<!DOCTYPE HTML>
<html>
    <body>
        <p>Before the script</p>
        <script>
            alert("hello world") ;
        </script>
        <p>After script</p>
    </body>
</html>
```
- `<script>` tag contains js code that will be exe when browser processes tag.
### External scripts
- Javascript can be placed into a separate/external file.
`<script src="/path/to/script.js"></script>`
`<script src="./script.js"></script>`  means script is in current folder
- Also possible to attach multiple scripts
`<script src="/path/to/script1.js"></script>`
`<script src="/path/to/script2.js"></script>`
- External scripts are downloaded and stored in cache to be used in future visits
- NOTE: Script must either be embedded/internal or external. Can't combine both.
```javascript
//won't work bc combining both embedded and external scripts
<script src='file.js'>
    console.log('stuff');
</script>
```
```javascript
//scripts can be separated for them to work properly
<script src='file.js'></script>
<script>
    console.log('stuff');
</script>
```
## Summary
- `<script>` tag used to add javascript to the page

# use strict
- ECMAScript 5 (ES5) added new features that modified language. These features are off by default and must be enabled
  by placing `use strict` at top of script. Generally not needed unless want to use new features.
# Variables
### A variable
```javascript
//let allows you to reassign value and is prefered over var
let greet = 'hello';
//var also allows reassign value but is old way and best to avoid
var greet = 'hello';
//const value can't be reassigned and should be used when possible
const b_day = "1.12.03";
```
# Data types
- There are 8 basic data types in javascript. 
### Number
Number type represents both interger and floating point numbers. Number type also represents Infinity, - Infinity and NaN
- Infinity represents Infinity
- NaN represents computational error. Ex. ` 'not a number'/ 2`
- NaN is sticky: Meaning further mathematical operations on NaN returns NaN
```javascript
console.log(NaN + 1); //NaN
console.log(3 * NaN); //NaN
```
- Mathematical operations are safe. Dividing by 0, treating strings as numbers, etc won't lead to fatal errors. 
  Worst case result will be NaN

### BigInt
Number type can't safely represent int values > (2^53-1) (9007199254740991) or less than -(2^53-1) - (9007199254740991)
- BigInt is created by appending `n` at end of an int
`const big_int = 121213219392139129391293192n`

### String
In javascript there are 3 types of quotes:
- Double quotes: `"hello"`
- Single quotes: 'hello'
- Backticks: Allow to embed variables and expressions into a string by wrapping them in `${}`
```javascript
let name ='isaac';
console.log(`hello, ${name}`);  //hello, isaac
```
- The expression inside ${} is evaluated and result becomes part of string.

### Boolean
Boolean type has 2 values: true and false
```javascript
let safe = true;
```

### Null 
Null is a special value that represents "empty" or "unknown value"
```javascript
let age = null;
```

### Undefined
Undefined is a special value meaning _value is not assigned_
- If variable is declared but not assigned, value is undefined
```javascript
let age; // automatically set to undefined
```

### symbol
Used to create unique id for objects

### Object
All previous types are primitive bc they contain a single item. 
- Objects store collections of data

### typeof operator
typeof returns string with type of operand
```javascript
typeof 0;    //"number"
typeof true; //"boolean"
```
