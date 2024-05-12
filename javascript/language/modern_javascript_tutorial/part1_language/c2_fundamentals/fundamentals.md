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

# Interaction: Alert, prompt, confirm
### Alert
Alert shows a message and waits for user to click 'ok'. 
```javascript
alert("hello");
```
### Prompt
Promt accepts 2 args
```javascript
result = prompt(title, [default])
```
Shows a window with text msg, an input field and the buttons 'ok' and 'cancel'.
- title is text displayed
- default is optional second parameter, the initial value of input field
- The [] around default means parameter is optional, not required.
- If user clicks 'ok' input value is returned, else null is returned if 'cancel' was clicked
```javascript
let age = prompt("How old are you?", 100);
alert(`Your are ${age} years old`);  //will return input or 100 if user hit cancel
```
- It is recommended to always supply second arg bc internet explorer will insert text "undefined" into prompt
```javascript
let test = prompt("test", '');
```
### Confirm
```javascript
result = confirm(question);
```
- confirm shows window with question and 'ok' and 'cancel' buttoms
- 'ok' returns true
- 'cancel' returns false

# Type conversions
### String conversion
`String(value)`: Converts value to a string
```javascript
let value = true;
console.log(typeof value);  //boolean
value = String(value);
console.log(typeof value);  //string
```
### Numeric conversion
`Number(value)`: Converts value to a number
```
let value = "123";
console.log(typeof value);  //string
value = Number(value);
console.log(typeof value);  //number
```
- If string is not a valid number result is NaN
```javascript
let age = Number("siriggej");
console.log(age);  //NaN
```
- Undefined becomes NaN
- null becomes 0
- true and false become 1 and 0
- string becomes NaN

### Boolean conversion
`Boolean(value)`: Converts value to boolean
- Values that are empty like 0, "", null, undefined and NaN become false
- Other values become true
```javascript
Boolean(1); //true
Boolean(0); //false
Boolean("hello"); //true
Boolean("");      //false
```
# Basic operators and math
### Terms: unary, binary and operand
- Operand: is what operators are applied to. For ex. 5 * 2. There are 2 operands. Left operand is 5 and right operand is 2.
- Unary: Operator is unary, if it has a single operand. 
    Ex. Unary negation: 
    ```javascript
    let x = 1;
    x = -x;
    ```
- Binary: Operator is binary, if it has 2 operands. 
    Ex. Substraction
    ```javascript
    let x = 1
    let y = 3;
    y - x; //2
    ```
- Following Math operations are supported:
    - Addition: `+`
    - Substraction: `-`
    - Multiplication: `*`
    - Division: `/`
    - Remainder: `%`
    - Exponentiation: `**`
### Exponentiation **
`a ** b` raises a to the power of b: `a^b`
```javascript
2 ** 2;// 2^2 = 4
2 ** 3;// 2^3 = 8
2 ** 4;// 2^4 = 16
4 **(1/2); //2. Power of 1/2 is same as square root
8 **(1/3); //2. Power of 1/3 is same as cubit root
```
### Remainder %
`a % b` is remainder of integer division of a by b
```javascript
5 % 2; //1, the remainder of 5 divided by 2
8 % 3; //2, the remainder of 8 divided by 3
8 % 4; //0, the remainder of 8 divided by 4
```
### String concatenation with binary + 
- If binary `+` is applied to strings, it concatenates them
```javascript
let s = "my" + "string";// mystring
```
- If any of the operands is a string, the others are conversted to string!
```javascript
'1' + 2;// "12"
2 + 2 + '1'; // "41" not "221"
'1' + 2 + 2; // "122" not "14"
```
- Operators works one after other. See 2nd Ex. First sums 2 + 2 = 4, then sums 4 + '1' which converts 4 to '4'
  resulting in '4' + '1' or '41'. 3rd Ex. since first operand is a string, '1', the remaining operands are converted 
  to strings.
- Binary `+` is the only operator that treats strings this way. Other operators convert operands to numbers
```javascript
6 - '2'; //4, converts '2' to a number
'6' / '2'; //3, converts both operands to numbers
```

### Numeric conversion, unary +
`+` exists in 2 forms: Binary form shown above and unary form
- Unary `+`: is applied to a single value. It converts non-numbers into numbers
```javascript
//no effect on numbers
let x = 1;
+x; //1
//converts non numbers
+true; //1
+""; //0
```
- + when applied to a non-number has same effect as Number()
```javascript
let apples = "2";
let oranges = "3";
//Both strings must be converted to numbers prior ot binary sum
+apples + +oranges; //5
//Above has same effect as
Number(apples) + Number(oranges); //5
```
- Note: The `+` must be prefixed due to higher precedence
### Operator precedence
If expression has more than 1 operator, execution order is determined by their precedence.
- Look up precedence table

### Bitwise Operators
- AND `&`
- OR `|`
- XOR `^`
- NOT `~`
- Left shift `<<`
- Right shift `>>`
- Zero-fill right shift `>>>`
