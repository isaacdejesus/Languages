# Recursion
## Recursion
1- When a function calls itself
2- until a specified condition is met
### Function calls itself
```
void f()
{
    print(1);
    f();  //calls itself
}

main()
{
    f();
}
```
- Above code calls f() in main which prints 1 then calls itself in infinite loop. Printing 1 until out of memory
- Note f() will go on forever since there is no stopping condition
```
 f(), line 2 <--- stack overflow
|f(), line 2 | This is the stack which keeps track of function calls.
|f(), line 2 | f() at the very top is latest call, and previous calls
|f(), line 2 | are waiting for newer calls to finish in order to return
|f(), line 2 | back to caller. However, since there is no end condition
|f(), line 2 | calls will continue to stack resulting to stack overflow
|f(), line 2 |
|f(), line 2 |
|f(), line 2 |
|f(), line 2 |
|f(), line 2 | This is the initial call made at main()
--------------
    Stack
```
### Base condition
```c++
int count = 0;
void f()
{
    if(count == 4)  <-- base case. stops recursion
        return;
    print(count);
    count++;
    f();
}
main()
{
    f();
}
```
- Now there is a base condition that will stop recursion whenever count reaches 4
```
| f() | count = 4, base case reached, done. F() returns and no work is done on way back
| f() | count = 3, print 3, count++ => 4. Above call returned, so this one returns as well.
| f() | count = 2, print 2, count++ => 3. Above call returned, so this one returns as well.
| f() | count = 1, print 1, count++ => 2. Above call returned, so this one returns as well.
| f() | count = 0, print 0, count++ => 1. Above call returned, so this one returns as well.
------- Upon returning to first call, function exits recursion and it's done.
Stack
```
- Note there can be more than 1 base condition
- Recursion tree: Recursion can always be traced in form of a tree
- In this case result is linear recursion
```
f() -> f() -> f() -> f() -> f()
 0      1       2     3      x return
 <-    <-       <-    <-     <- no work on return
```

