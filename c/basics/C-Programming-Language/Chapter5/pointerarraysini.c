#include <stdio.h>

char *month_name(int);
int mmain()
{
    //declares a 2d array
    int a[10][20];
    //declares an array of pointers
    int *b[10];    
    //see page 114 for picture.
    //The pointer array creates 10 pointers which can hold arrays of various lenghts
    return 0;
}

char *month_name(int n)
{
    static char *name[] ={
        "Illegal month", "January", "February", "March",
        "April", "May", "June", "July", "August", "September",
        "November", "December"};
    return (n < 1 || n > 12) ? name[0] : name[n];
}

//*name creates an array of pointers 
//each pointer holds an array which is a month
