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
```c++
#include<bits/stdc++.h>
void f(int i, int n)
{
    if(i > n)
        return;
    f(i + 1, n);
    std::cout<<i<<'\n';  //work done at return time
}
```
### Sum of first n numbers parametized
- Tail recursion: Work done at call time and result is returned down stack to caller on way back
```c++
#include<bits/stdc++.h>
void f(int sum, int n)
{
    if(n < 1)
    {
        std::cout<<sum<<'\n';
        return;
    }
    f(sum + n, n - 1);
}
int main()
{
    f(0, 3);
    f(0, 5);
}
```
```
recursion tree
f(0, 3) -> f(3, 2) -> f(5, 1) -> f(6, 0) base case return sum of 6 back to down call stack
  sum 0      sum 3      sum 5      sum 6
  6<--       6<--       6<--       6<--
  Initial call returns 6
```
### Sum of first n numbers functional/no parameters
- Head recursion: Result is calc at return time on way back to caller/initial call
```c++
#include<bits/stdc++.h>
int f(int n)
{
    if(n == 0)
        return 0;
    return n + f(n - 1);
}
```
```
f(3) -----> f(2) -----> f(1) -----> f(0)  base case, return 0 and start computing result
<-3 + 3     <-2 + 1     <-1 + 0     <-0
Initial call computes final result and returns 6
```
### Factorial of n
- Head recursion: Result is calc on way back from recursion
```c++
#include<bits/stdc++.h>
int f(int n)
{
    if(n < 1)
        return 1;
    return n * f(n - 1);
}
```
### Reverse arr
Given arr: 1 2 3 4 2
Return:    2 4 3 2 1
- use 2 pointers and recurse swapping values at pointers. Advancing pointers then call recursion on new pointers
```
1 2 3 4 2
l       r
swap, advance pointers and call rec
2 2 3 4 1
  l   r
swap, advance pointers and call rec
2 4 3 2 1
    l/r
Base case l == r or l > r(pointers crossed paths)
```
```c++
#include<bits/stdc++.h>
void swap(std::vector<int>& vec, int l, int r)
{
    int temp = vec[l];
    vec[l] = vec[r];
    vec[r] = temp;
}
void f(std::vector<int>& vec, int l, int r)
{
    if(l >= r)
        return;
    swap(vec, l, r);
    f(vec, l + 1, r - 1);
}
int main()
{
    std::vector<int> vec = {1, 2, 3, 4, 2};
    f(vec, 0, vec.size() - 1);
    for(auto val: vec)
        std::cout<<val<<' ';
    std::cout<<'\n';
}
```
- f() can be rewritten to use a single pointer and using formula: n - l - 1 to figure out the r pointer
  and base condition being l >= n/2. Meaning l pointer reached mid of array .:. done swapping
```
0 1 2 3 4 
l       n - l - 1 => 5 - 0 - 1 => 4

0 1 2 3 4 
  l   n - l - 1 => 5 - 1 - 1 => 3

0 1 2 3 4 
    l  n - l - 1 => 5 - 2 - 1 => 2
    l/r are same .:. done swapping
```
```c++
void f2(std::vector<int>& vec, int l)
{
    if(l >= vec.size()/2)
        return;
    swap(vec, l, vec.size() - l - 1);
    f2(vec,  l + 1);
}
```
### Check if string is palindrome
- palindrome, string reads same forward and backwards
- palindrome, reads same after reversal
```
madam  -reverse->  madam
```
- Single pointer strat used to reverse an arr can be used to check string by comparing
  chars at pointers from outside in
```
madam
l   r  compare chars at l/r

madam
 l r  compare chars at l/r

madam
  l/r l >= r base case/done

keep checking as long as chars match
if mismatch then it is not palindrome .:. return false
if reach end of loop and no mismatch then it is a palindrome
```
- Note: bc function isn't void, has a return type then the recursive call must have the return keyword!
.:. all rec f() not void must return something
```c++
#include<bits/stdc++.h>
bool f(std::string& str,int l)
{
    if(l >= str.size()/2)
        return true;
    if(str[l] != str[str.size() - l - 1])
        return false;
    return f(str,  l + 1);
}
```
### Fibbonacci
- Unlike previous problems fib makes multiple rec calls
```
0th fib number is 0
1st fib number is 1
2nd fib number is 1
3rd fib number is sum of last 2
0 1 1 2 3 5 8 13 21 34 ...
```
- Write a function that returns the nth fib number
```c++
#include<bits/stdc++.h>
int f(int n)
{
    if(n <= 1)
        return n;
    //return f(n - 1) + f(n - 2);
    //below does same as above
    int last = f(n - 1);  //will run to completion
    int second_last = f(n - 2);  //won't run until above rec call finishes and returns
    return last + second_last;
}
```
- Recall func will be read line by line .:. last = f(n -1) call will run to completion and rest of code
  won't run until last = f(n - 1) returns
- Since fib makes multiple recursion calls, result will be a branched recursion tree
```
                            f(4)        2 + 1 => 3
                            /   \
            1 + 1        f(3)    f(2)   1 + 0
                         / \     /  \
            1 + 0     f(2) f(1) f(1) f(0)
                      /\
                    f(1)f(0)
f(1) and f(0) are base cases that return 1 and 0
Call are exe in order called .:. left branch is exe first then right branch
left: f(4) -> f(3) -> f(2) -> f(1) -> f(0) -> f(1)
right: f(2) -> f(1) -> f(0)
```
- Note fib uses head recursion .:. result is calc at return time
