#include <stdio.h>
//computes average
int main(void)
{
    double n1, n2, n3;
    double average;

    puts( "Compute the average of 3 numbers" );
    puts( "--------------------------------" );
    printf( "Please input 3 numbers: " );
    scanf( "%lg%lg%lg", &n1, &n2, &n3 );  //take user input
    average = (n1 + n2 + n3)/ 3.0;
    printf("The average of %g, %g, and %g = %g \n\n", n1, n2, n3, average);
    return 0;
}
