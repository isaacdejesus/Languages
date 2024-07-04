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
### Count digits
- Given a number return number of digits
```c++
#include<bits/stdc++.h>
int count_digits (int n)
{
    int count = 0;
    while(n > 0)
    {
        count++;
        n = n/10;
    }
    return count;
}
int count_digits_(int n)
{
    int count = (int)(log10(n) + 1);
    return count;
}
```
- The second solution uses log10 to calc # of digits. Works as follows:
```
log10(7789) => 3.81. If cast result to int result becomes 3, then add 1 to get total digits
log10(7789) + 1 = 3 + 1 = 4
```
### Reverse a number
Given a number return reversed number
- Recall digit extraction returns digits in reverse order
- Need to multiply current reversed number * 10 prior to adding newly extracted digit
```
N = 7789
reverse_number = 0

current_digit = N % 10;  //9
N = N/10;  //778
reverse_number = reverse_number * 10 + current_digit;  //0 * 10 + 9 => 9

current_digit = N % 10;  //8
N = N/10;  //77
reverse_number = reverse_number * 10 + current_digit;  //9 * 10 + 8 => 98

current_digit = N % 10;  //7
N = N/10;  //7
reverse_number = reverse_number * 10 + current_digit;  //98 * 10 + 7 => 987

current_digit = N % 10;  //7
N = N/10;  //0
reverse_number = reverse_number * 10 + current_digit;  //987 * 10 + 7 => 9877
```

```c++
#include<bits/stdc++.h>
int reverse_number(int n)
{
    int reversed_number = 0;
    while(n > 0)
    {
        int last_digit = n % 10;
        n = n /10;
        reversed_number = reversed_number * 10 + last_digit;
    }
    return reversed_number;
}
```
### Check palindrome
- Given a number check if it is palindrome
- Reverse the number then compare to original
```c++
#include<bits/stdc++.h>
bool reverse_number(int n)
{
    int reversed_number = 0;
    int original_number = n;
    while(n > 0)
    {
        int last_digit = n % 10;
        n = n /10;
        reversed_number = reversed_number * 10 + last_digit;
    }
    return reversed_number == original_number;
}
```
### Armstrong numbers
- Armstrong number is a number whose digits exponentially added to the number of digits in original number add up to original number
```
371 = 3^3 + 7^3 + 1^3 => 371
1634 = 1^4 + 6^4 + 3^4 + 4^4 => 1634
```
```c++
#include<bits/stdc++.h>
bool armstrong_number(int n){
    int original_number = n;
    int sum = 0;
    int last_digit = 0;
    int count_digits = (int) (log10(n) + 1);
    while(n > 0)
    {
        last_digit = n % 10;
        n = n/10;
        sum = sum + pow(last_digit, count_digits);
    }
    return sum == original_number;
}
```
### print all divisors
- Given a number return all values that completely divides number
```
N = 36 => 1, 2, 3, 4, 6, 9, 12, 18, 36.
Other values result in a fraction/residue .:. Do not completely divide the number
```
- From above example we know possible dividors range between 1  to n bc any values larger than n will
  not fully divide the value. .:. Need to loop 1 -> n and attempt to divide n % i. If remainder is 0
  then i is a dividor.
```c++
//O(n)
#include<bits/stdc++.h>
void print_divisors(int n)
{
    for(int i = 1; i <=n; i++)
    {
        if((n % i) == 0)
            std::cout<<i<<" ";
    }
}
```
- Note that all divisors can be found in square root time
```
divisors of 36
[first operand] [operator] [second operand]
1 x 36
2 x 18
3 x 12
4 x 9
6 x 6  <--- square root of 36 =>  6
9 x 4
12 x 3
18 x 2
36 x 1

Note that factors after square root of 36 or 6 (6 x 6) are just the second operand/factor used to get first half of factors
```
```c++
void print_divs_improved(int n)  //gets rid of sqrt function
{
    std::vector<int> list;
    for(int i = 1; i * i <= n; i++)
    {
        if(n % i == 0)
        {
            list.push_back(i);  //i is a divisor
            if((n/i) != i)      //check if second operand isn't same as i
                list.push_back(n/i);  //if different then add to list since it is also a divisor
        }
    }
    sort(list.begin(), list.end());
    for(auto it: list)
        std::cout<<it<<" ";
}
```
- First check if current i is a divisor, if it is add to list.
- Then obtain second operand (n/i) and add to list if it's not == i. Prevents adding 6 x 6 twice
- Note: Method results in divisors being returned out of order.:. results are stored in vector then sorted.
```
1 x 36 => first operand 1, second operand n/1 or 36 .:. add 1 and 36 to list
2 x 18 => first operand 2, second operand n/2 or 18 .:. add 2 and 18 to list
3 x 12 => first operand 3, second operand n/3 or 12 .:. add 3 and 12 to list
4 x 9 =>  first operand 4, second operand n/4 or 9  .:. add 4 and 9 to list
6 x 6 =>  first operand 6, second operand n/6 or 6 first and second operand are both 6
.:. only add the first operand to list.
Result: [1, 36, 2, 18, 3, 12, 4, 9, 6]
Sort() => [1, 2, 3, 4, 6, 9, 12, 18, 36]
```
### Prime number check
- Given a number check if prime
- Prime number has exactly 2 factors 1 and itself. Only divisible by 1 and itself
```
11 is prime only divisible by 1 and 11
13 is prime only divisible by 1 and 13
5 is prime  only divisible by 1 and 5
```
```c++
#include<bits/stdc++.h>
bool check_prime(int n)
{
    int count = 0;
    for(int i = 1; i*i <=n; i++)
    {
        if(n % i == 0)
        {
            count++;
            if((n/i) != i)
                count++;
        }
    }
    if(count == 2)
        return 1;
    else 
        return 0;
}
```
- Above makes uses of previous problem/solution. Running loop square root times to check all possible
  factors of a number. If number of factors is exactly 2 then it is a prime number.
### GCD or HCF
- GDC - Greatest Common Divisor
- HCF - Highest Common Factor
- Given 2 numbers, 9 and 12. Find GCD/HCF that divides both numbers
```
Factors of 9: 1, 3, 9
Factors of 12: 1, 2, 3, 4, 6, 12
Common factors of both 9 and 12: 1, 3
Highest is 3, .:. 3 is GCD/HCF

Factors of 11: 1, 11
Factors of 13: 1, 13
Common factors of both 11 and 13: 1
Note there's always a common factor since 1 divides all numbers

Given 20 and 40
Note that 20 is a factor for itself and for 40
```
- Solution: Loop from 1 to smallest number bc dividing smallest number by any number > than itself will
  result in fraction .:. smallest number is upper limit. For each i, check if it divides both numbers.
  If current i divides both numbers it becomes newest/greatest divisor.
  ```
  Ex. 9 and 12
  int greatest_div = 0;
  i = 1 => 1 divides both 9 and 12 .:. greatest_div = 1
  i = 2 => 1 doesn't divide both
  i = 3 => 3 divides both 9 and 12 .:. greatest_div = 3
  i = 4 => 4 doesn't divide both
  i = 5 => 5 doesn't divide both
  ... and so on. Final answer will be 3
  ```
- Above algo is O(min(number1, number2)) since loop up until smallest number
### Euclidean algorith
- Euclidean algo can be used to find GCD/HCF
- gcd(a, b) = gcd(a - b, b). Where a > b
```
gcd(20, 15) = gcd(5, 15) = gcd(15, 5) = gcd(10, 5) = gcd(5, 5) = gcd(0, 5) .:. GCD is 5
problem is reduced at each step until one of them numbers becomes 0, then the nonzero 
number is the gcd

a = 52, b = 10
gcd(52, 10) => gdc(42, 10) => gcd(32, 10) => gcd(22, 10) => gcd(12, 10) => gcd(10, 2) =>
gcd(8, 2) => gcd(6, 2) => gcd(4, 2) => gcd(2, 2) => gcd(0, 2)

Note that algo can still be linear and take a long time as shown above.
Also note that since substracting 10 at each step, the substraction can be replaced by
division such as: gcd(52 % 10, 10) => gcd(2, 10) would allow to skip steps from beginning
up to gcd(10, 2) in a single step instead of many substractions

.:. formula becomes: gcd(a, b) == gcd(a % b, b)
Greatest % smallest -> until one of them becomes 0
If one is 0, the other is gcd
```


