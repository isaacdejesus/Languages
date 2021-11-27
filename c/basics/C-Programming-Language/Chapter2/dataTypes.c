#include <stdio.h>

//basic data types
//char a single byte. Holds one character
//int holds an int. 16 or 32 bits long
//float single precision floating point
//double double precision floating point. About 2x precision of the float

//Quantifiers can be applied to the above basic  data types
//short usually 16 bits long
//long at least 32 bits long
//short must be smaller than int and int can't be longer than long

//Qualifiers can be applied to char or ints
//unsigned always positive or 0. Calculated 2^n. Ex. if chars 8 bits. Then unsigned char
//holds values between 0-255. 2^8
//signed can be negative, for 8 bits, then values range between -128 to 127
int main()
{
    short int var1;
    long int var2;
    //the int can be omitted
    short var3;
    long var4;

    long double;

    return 0;
}

