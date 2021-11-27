#include <stdio.h>

int main()
{
    //Variables must be declared before use and assigned a value.
    //const qualifier can be used at declaration to specify that value will not change
    const char toRemain[] ="My value can not be changed!";
    //const can also be used in array arguments. Tells function can not modify array
    void certainFunction( const arr[]);


    return 0;
}
