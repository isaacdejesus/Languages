//Rewrite of temp conversion program to use functions

#include <stdio.h>
float toCelsius(float fahr);

int main()
{
    float fahr;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;

    while(fahr <= upper)
    {
        printf("%3.0f %6.1f\n", fahr, toCelsius(fahr));
        fahr = fahr + step;
    }
   
   return 0; 
}

float toCelsius( float fahr)
{
    return (5.0/9.0) * (fahr - 32.0);
} 
