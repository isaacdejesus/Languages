# Basic maths for DSA
### Extract digits from a number
- number % 10 returns the least significan digit in the number
- Recall % returns the remainder of division .:. 
```
89 % 10 returns 9 bc 80 divides evenly into 10 leaving 9 as remainder/decimal
31 % 10 returns 1 bc 30 divides evenly into 10 leaving 1 as remainder/decimal
```
- number / 10 removes the least significant digit from number
- Recall integer data type throws away the decimal portion
```
89 / 10 returns 8 bc 89/10 returns 8.9 and int data type only takes the 8/integer portion
31 / 10 returns 3 bc 31/10 returns 3.1 and int data type only takes the 3/integer portion
```
### Using extraction to process number
- Note: Since we are extracting numbers from the back, number is processed in reverse order
- Reduce 7789
```
int current_digit;
int number = 7789;
//Get least sig digit
current_digit = 7789 % 10;  //9
print(current_digit); // 9

//Remove least sig digit
number = number/10;  //778

//get least sig digit
curent_digit = 778 % 10;  //8
print(current_digit); //8

//Remove least sig digit
number = number/10; //77

//get least sig digit
curent_digit = 77 % 10;  //7
print(current_digit);  //7

//Remove least dig digit
number = number/10;  //7

//get least sig digit
current_digit = 7 % 10;  //7
print(current_digit);  //7

//Remove least sig digit
number = number/10; //0

number = 0; // .:. Done!

printed: 9 8 7 7
```
- General extraction code is
```
int number;
while(number > 0 )
{
    digit = number % 10;
    print/process digit;
    number = number / 10;
}
```
