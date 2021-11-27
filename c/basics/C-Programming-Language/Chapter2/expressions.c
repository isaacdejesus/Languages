#include <stdio.h>
int main()
{
    //+=, *=, /=, -=,  assignment operator can be used instead of i = i + 2
    int i = 0;
    i += 2;
    //assignment op can also be used in more complex expressions
    int x, y;
    x = y = 1;
    //x = x * (y + 1) can be replaced by
    x *= y + 1;
    return 0;
}
