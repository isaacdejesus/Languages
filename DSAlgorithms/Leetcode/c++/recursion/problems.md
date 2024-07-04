### Print name n times using recursion
```c++
#include<bits/stdc++.h>
void f(int i, int n)
{
    if(i > n)   //base case
        return;
    std::cout<<"isaac"<<'\n';  //work done at call time
    f(++i, n);  //increment i and recurse
}
```
- Note, passing i to function to keep track of function calls, to avoid using a global variable
- Whenever function has been called i times > n the function terminates
### Print numbers from 1 - n using recursion
```c++
#include<bits/stdc++.h>
void f(int i, int n)
{
    if(i > n)
        return;
    std::cout<<i<<'\n';   //work done at call time
    f(++i, n);
}
```
### print numbers from n - 1 using recursion
```c++
#include<bits/stdc++.h>
void f(int i, int n)
{
    if(i < 1)
        return;
    std::cout<<i<<'\n';   //work done at call time
    f(--i, n);
}
void f2(int i, int n) //note f2 prints at return time/head recursion
{
    if(i >= n)
        return;
    f2(++i, n);
    std::cout<<i<<'\n';   //work done at return time
}
int main()
{
    //f(5, 5);
    //f(7, 7);
    f2(0, 5);
}
```
### Print numbers from 1 - n without using ++. Using backtracking/head recursion
- Note all the previous problems used tail recursion. Meaning work was done at call time
- f2 does use head recursion
- This problem and next will use head recursion. Work wil be done at return time
```c++
#include<bits/stdc++.h>
void f(int i, int n)
{
    if(i < 1)
        return;
    f(i - 1, n);
    std::cout<<i<<'\n';  //work done at return time
}
int main()
{
    f(3, 3);
    f(5, 5);
}
```
### print n - 1 without using --. Using backtracking/head recursion
