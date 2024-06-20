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
``
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
``
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
``
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
``
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
