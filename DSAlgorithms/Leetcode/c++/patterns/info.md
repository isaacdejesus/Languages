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
