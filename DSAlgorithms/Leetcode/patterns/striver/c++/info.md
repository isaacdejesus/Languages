Patterns are important to undertanding loops and being able to solve advanced problems
## Patterns are solved using nested loops: 
- Where first/outer loop is for rows and second/inner loop for columns.
- .:. First/outer loop iterates rows
- .:. Second/inner loop iterates each col of the given row

## Strategy to solve pattern questions
- Outer loop, count the number of lines/rows
- Inner loop, focus on colums and connect them to the rows
- Work/print should be done inside inner loop
- Observe symmetry [optional]

### Q: Code following pattern -
```
* * * *
* * * *
* * * *
* * * *
```
```c++
#include <bits/stdc++.h>
void print_1(int n)
{
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col < n; col++)
        {
            std::cout<<"* ";
        }
        std::cout<<'\n';
    }
}
```
### Q: Code following pattern -
```
*
* *
* * *
* * * *
* * * * *
```
```c++
#include <bits/stdc++.h>
void pattern_2(int n)
{
    for(int row = 0; row < n; row++)
    {
        for(int col = 0; col <= row; col++)
        {
            std::cout<<"* ";
        }
        std::cout<<'\n';
    }
}
```
### Q: Code following pattern -
```
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
```
```c++
#include <bits/stdc++.h>
void pattern_3(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= row; col++)
        {
            std::cout<<col<<" ";
        }
        std::cout<<'\n';
    }
}
```
### Q: Code following pattern -
```
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
```
```c++
#include <bits/stdc++.h>
void pattern_3(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= row; col++)
        {
            std::cout<<row<<" ";
        }
        std::cout<<'\n';
    }
}
```
### Q: Code following pattern -
```
    x x x x x
    x x x x
    x x x
    x x
    x
```
```c++
#include <bits/stdc++.h>
void pattern_5(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 0; col < n - row + 1; col++)
        {
            std::cout<<"* ";
        }
        std::cout<<'\n';
    }
}
```
### Q: Code following pattern -
```
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2
    1
```
```c++
#include <bits/stdc++.h>
void pattern_6(int n)
{
    for(int row = 1; row <= n; row++)
    {
        for(int col = 1; col <= n - row + 1; col++)
        {
            std::cout<<col<<" ";
        }
        std::cout<<'\n';
    }
}
```
### Q: Code following pattern -
```
    x
   xxx
  xxxxx
 xxxxxxx
xxxxxxxxx
```
- Note for each row the pattern is `" "` followed by `*` followed by `" "`
```
                [n - row - 1, 2 * 1 + 1, n - row - 1]
0     x         [4 spaces, 1 star, 4 spaces]
1    xxx        [3 spaces, 3 stars, 3 spaces]
2   xxxxx       [2 spaces, 5 stars, 2 spaces]
3  xxxxxxx      [1 space, 7 stars, 1 space]
4 xxxxxxxxx     [0 space, 9 stars, 0 space]
```
- .:. Will need 3 inner loops: First loop to place spaces, Second loop to place stars and Third loop to add more spaces
```c++
#include <bits/stdc++.h>
void pattern_7(int n)
{
    for(int row = 0; row < n; row++)
    {
        //Adds first set of spaces
        for(int col = 0; col < n - row - 1; col++)
            std::cout<<" ";
        //stars
        for(int col = 0; col < 2 * row + 1; col++)
            std::cout<<"*";
        //Adds last set of spaces
        for(int col = 0; col < n - row - 1; col++)
            std::cout<<" ";
        std::cout<<'\n';
    }
}
```
### Q: Code following pattern -
```
    xxxxxxxxx
     xxxxxxx
      xxxxx
       xxx
        x
```
```
                        [space == row, 2n - (2*row + 1), space == row]
    0 xxxxxxxxx         [0 space, 9 stars, 0 space]
    1  xxxxxxx          [1 space, 7 stars, 1 space]
    2   xxxxx           [2 spaces, 5 stars, 2 spaces]
    3    xxx            [3 spaces, 3 stars, 3 spaces]
    4     x             [4 spaces, 1 star, 4 spaces]
```
```c++
#include <bits/stdc++.h>
void pattern_8(int n)
{
    for(int row = 0; row < n; row++)
    {
        //spaces
        for(int col = 0; col < row; col++)
            std::cout<<" ";
        //stars
        for(int col = 0; col < 2*n - (2 * row + 1); col++)
            std::cout<<"*";
        //spaces
        for(int col = 0; col < row; col++)
            std::cout<<" ";
        std::cout<<'\n';
    }
}
```
### Q: Code following pattern -
```
        x
       xxx
      xxxxx
     xxxxxxx
    xxxxxxxxx
    xxxxxxxxx
     xxxxxxx
      xxxxx
       xxx
        x
```
```
                        [n - row - 1, 2 * 1 + 1, n - row - 1]   
    0     x             [4 spaces, 1 star, 4 spaces]
    1    xxx            [3 spaces, 3 stars, 3 spaces]
    2   xxxxx           [2 spaces, 5 stars, 2 spaces]
    3  xxxxxxx          [1 space, 7 stars, 1 space]
    4 xxxxxxxxx         [0 space, 9 stars, 0 space]
                        [space == row, 2n - (2*row + 1), space == row]
    0 xxxxxxxxx         [0 space, 9 stars, 0 space]
    1  xxxxxxx          [1 space, 7 stars, 1 space]
    2   xxxxx           [2 spaces, 5 stars, 2 spaces]
    3    xxx            [3 spaces, 3 stars, 3 spaces]
    4     x             [4 spaces, 1 star, 4 spaces]
```
```c++
#include <bits/stdc++.h>
void pattern_7(int n)
{
    for(int row = 0; row < n; row++)
    {
        //Adds first set of spaces
        for(int col = 0; col < n - row - 1; col++)
            std::cout<<" ";
        //stars
        for(int col = 0; col < 2 * row + 1; col++)
            std::cout<<"*";
        //Adds last set of spaces
        for(int col = 0; col < n - row - 1; col++)
            std::cout<<" ";
        std::cout<<'\n';
    }
}
void pattern_8(int n)
{
    for(int row = 0; row < n; row++)
    {
        //spaces
        for(int col = 0; col < row; col++)
            std::cout<<" ";
        //stars
        for(int col = 0; col < 2*n - (2 * row + 1); col++)
            std::cout<<"*";
        //spaces
        for(int col = 0; col < row; col++)
            std::cout<<" ";
        std::cout<<'\n';
    }
}
```
- Just call both previous pattern/functions

### Q: Code following pattern -
```
    n = 5, results in 9 rows .:. need 9 rows or 2*n - 1 rows
    Up until 5, stars == row
    after 5, stars = (2n - row)
    1 x         [1 star]
    2 xx        [2 stars]
    3 xxx       [3 stars]
    4 xxxx      [4 stars]
    5 xxxxx     [5 stars]
    6 xxxx      [4 stars]
    7 xxx       [3 stars]
    8 xx        [2 stars]
    9 *         [1 star]
```

```c++
#include <bits/stdc++.h>
void pattern_10(int n)
{
    for(int row = 1; row <= 2 * n - 1; row++)
    {
        int stars = row;
        if(row > n) 
            stars = 2 * n - row;
        for(int col = 1; col <= stars; col++)
        {
            std::cout<<"*";
        }
        std::cout<<'\n';
    }
}
```
### Q: Code following pattern -
```
1
0 1
1 0 1
0 1 0 1
1 0 1 0 1
```

```c++
#include <bits/stdc++.h>
void pattern_11(int n)
{
    int start = 1;
    for(int row = 0; row < n; row++)
    {
        if(row % 2 == 0)
            start = 1;
        else 
            start = 0;
        for(int col = 0; col <= row; col++)
        {
            std::cout<<start;
            start = 1 - start;
        }
        std::cout<<'\n';
    }
}
```
### Q: Code following pattern -
```
1      1
12    21
123  321
12344321
```
```
4 rows, .:. loop runs 4 times. 
The colums are made out of  [ number, space, number ]
1      1                    [ 1 number, 6 spaces, 1 number ]
12    21                    [ 2 numbers, 4 spaces, 2 numbers ]
123  321                    [ 3 numbers, 2 spaces, 3 numbers ]
12344321                    [ 4 numbers, 0 space, 4 numbers ]
 - Note the spaces are reduced by 2 every row .:. just need to calc starter # of spaces with
   formula 2 * (n -1), then reduce spacing by 2 at end of each row/loop
```c++
#include <bits/stdc++.h>
void pattern_12(int n)
{
    int space = 2 * (n - 1);
    for(int row = 1; row <= n; row++)
    {
        //print numbers
        for(int col = 1; col <= row; col++)
            std::cout<<col;
        //print spaces
        for(int col = 1; col <= space; col++)
            std::cout<<" ";
        for(int col = row; col >= 1; col--)
            std::cout<<col;
        std::cout<<'\n';
        space -= 2;
    }
}
```
### Q: Code pattern -
```
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```
```
cols match the row size. Ex. row 2 has 2 cols/numbers
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
```
```c++
#include <bits/stdc++.h>
void pattern_13(int n)
{
    int number = 1;
    for(int row = 1; row <= n; row++)
    {
        //print numbers
        for(int col = 1; col <= row; col++)
        {
            std::cout<<number<<" ";
            number++;
        }
        std::cout<<'\n';
    }
}
```
### Q: Code pattern -
```
a
ab
abc
abcd
abcde
```
```c++
#include <bits/stdc++.h>
void pattern_14(int n)
{
    for(int row = 0; row <= n; row++)
    {
        for(char ch = 'A'; ch <= 'A' + row; ch++)
        { //Loop char which in this case represent cols. Loop from 'A' to 'A' + row char
            std::cout<<ch<<" ";  //ex, if row is 2, We would output A, B, C since C is A + 2 in ascii
        }
        std::cout<<'\n';
    }
}
```
### Q: Code pattern -
```
abcde
abcd
abc
ab
a
```
```c++
#include <bits/stdc++.h>
void pattern_15(int n)
{
    for(int row = 0; row < n; row++)
    {
        for(char ch = 'A'; ch <= 'A' + (n - row - 1); ch++)
        { //Loop char which in this case represent cols. Loop from 'A' to 'A' + row char
            std::cout<<ch<<" ";  //ex, if row is 2, We would output A, B, C since C is A + 2 in ascii
        }
        std::cout<<'\n';
    }
}
```
### Q: Code pattern -
```
a
bb
ccc
dddd
eeeee
```
```c++
#include <bits/stdc++.h>
void pattern_16(int n)
{
    for(int row = 0; row < n; row++)
    {
        char ch = 'A' + row;
        for(int col = 0; col <= row ; col++)
        { //Loop char which in this case represent cols. Loop from 'A' to 'A' + row char
            std::cout<<ch<<" ";  //ex, if row is 2, We would output A, B, C since C is A + 2 in ascii
        }
        std::cout<<'\n';
    }
}
```
### Q: Code pattern -
```
Outer loop runs n times. There are n rows
Pattern is          [space, letters, space]
                    [n - row - 1, 2 * row + 1 ,n - row - 1]

0     A
1    ABA
2   ABCBA
3  ABCDCBA
4 ABCDEDCBA
```
```c++
#include <bits/stdc++.h>
void pattern_7(int n)
{
    for(int row = 0; row < n; row++)
    {
        //spaces
        for(int col = 0; col < n - row - 1; col++)
            std::cout<<" ";
        //chars
        char ch = 'A';
        int break_point = (2 * row + 1) /2;
        for(int col = 1; col <= 2 * row + 1; col++)
        {
            std::cout<<ch;
            if(col <= break_point)
                ch++;
            else
                ch--;
        }
        //spaces
        for(int col = 0; col < n - row - 1; col++)
            std::cout<<" ";
        std::cout<<'\n';
    }
}
```
### Q: Code pattern -
```
E 
D E
C D E
B C D E
A B C D E
```
```c++
#include <bits/stdc++.h>
void pattern_18(int n)
{
    for(int row = 0; row < n; row++)
    {
        for(char ch = 'E' - row; ch <= 'E'; ch++)
        {
            std::cout<<ch<<" ";
        }
        std::cout<<'\n';
    }
}
```
### Q: Code pattern -
```
xxxxxxxxxx
xxxx  xxxx
xxx    xxx
xx      xx
x        x
x        x
xx      xx
xxx    xxx
xxxx  xxxx
xxxxxxxxxx
```
```
                        [stars, spaces, stars]
                        [n - row, ini spaces + 2 , n - row]
xxxxxxxxxx              [5 stars, 0 space, 5 stars]
xxxx  xxxx              [4 stars, 2 spaces, 4 stars]
xxx    xxx              [3 stars, 4 spaces, 3 stars]
xx      xx              [2 stars, 6 spaces 2 stars]
x        x              [1 star, 8 spaces, 1 star]
                        
x        x              [1 star, 8 spaces, 1 start]
xx      xx              [2 stars, 6 spaces, 2 stars]
xxx    xxx              [3 stars, 4 spaces, 3 stars]
xxxx  xxxx              [4 stars, 2 spaces, 4 stars]
xxxxxxxxxx              [5 stars, 0 space, 5 stars]
```
```c++
#include <bits/stdc++.h>
void pattern_19(int n)
{
    int ini_spaces = 0;
    for(int row = 0; row < n; row++)
    {
        //stars
        for(int col = 1; col <= n - row; col++)
            std::cout<<"*";
        //spaces
        for(int col = 0; col < ini_spaces; col++)
            std::cout<<" ";
        //stars
        for(int col = 1; col <= n - row; col++)
            std::cout<<"*";
        ini_spaces += 2;
        std::cout<<'\n';
    }
    ini_spaces = 8;
    for(int row = 1; row <= n; row++)
    {
        //stars
        for(int col = 1; col <= row; col++)
            std::cout<<"*";
        //spaces
        for(int col = 0; col < ini_spaces; col++)
            std::cout<<" ";
        //stars
        for(int col = 1; col <= row; col++)
            std::cout<<"*";
        ini_spaces -= 2;
        std::cout<<'\n';

    }
}
```
### Q: code pattern -
```
x        x
xx      xx
xxx    xxx
xxxx  xxxx
xxxxxxxxxx
xxxx  xxxx
xxx    xxx
xx      xx
x        x
```

```c++
#include <bits/stdc++.h>
void pattern_10(int n)
{
    int spaces = 2 * n - 2;
    for(int row = 1; row <= 2 * n - 1; row++)
    {
        int stars = row;
        if(row > n)
            stars = 2 * n - row;
        //stars
        for(int col = 1; col <= stars; col++)
            std::cout<<"*";
        //spaces
        for(int col = 1; col <= spaces; col++)
            std::cout<<" ";
        //stars
        for(int col = 1; col <= stars; col++)
            std::cout<<"*";
        std::cout<<'\n';
        if(row < n)
            spaces -= 2;
        else
            spaces += 2;
    }
}

```
### Q: Code pattern -
```
xxxx
x  x
x  x
x  x
xxxx
```
```c++
#include <bits/stdc++.h>
void pattern_10(int n)
{
    for(int row = 0; row < n ; row++)
    {
        for(int col = 0; col < n; col++)
        {
            if(row == 0 || col == 0 || row == n - 1 || col == n - 1)
                std::cout<<"*";
            else 
                std::cout<<" ";

        }
        std::cout<<'\n';
    }
}
```
### Q: Code pattern:
```
4 4 4 4 4 4 4
4 3 3 3 3 3 4
4 3 2 2 2 3 4
4 3 2 1 2 3 4
4 3 2 2 2 3 4
4 3 3 3 3 3 4
4 4 4 4 4 4 4
```
```c++
#include <bits/stdc++.h>
void pattern_10(int n)
{
    for(int row = 0; row < 2 * n - 1 ; row++)
    {
        for(int col = 0; col < 2 * n - 1; col++)
        {
            int top = row;
            int left = col;
            int right = (2 * n - 2) - col;
            int down = (2 * n - 2) - row;
            std::cout<<(n - std::min(std::min(top, down), std::min(left, right)));
        }
        std::cout<<'\n';
    }
}

```
