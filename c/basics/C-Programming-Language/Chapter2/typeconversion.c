#include <stdio.h>
int main()
{
    //depending on the situation the prgram will perform type conversion
    //Casting allows you to force conversion
    //In the ex. below, sqrt expects a double.
    int a  = 9;
    sqrt((double) n);
    //functions will also enforce type conversion on the arguments to match the types defined on declaration.A
    double sqfunction ( double val);
    //Above function expects a double as argument. Therefore, if called with an int as argument
    //The int will be converted to double.
    sqfunction(9);
    //9 will be converted to 9.0
    return 0;
}
`
