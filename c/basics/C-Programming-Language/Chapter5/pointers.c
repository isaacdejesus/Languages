#include <stdio.h>

void regularSwap(int , int);
void pointerSwap( int *, int *);
int main()
{
    //pointer is a group of cells 2-4 that can hold an address
    //Unary operator & gives the address of an object
    //Given c is a char and p a pointer to it.
    //p = &c; will assign the pointer p with the address of c
    //Unary operator * indirection or dereferencing operator
    //* when applies to a pointer yields object pointer is pointing to
    int x = 1, y = 2, z[10];
    int *p;
    p = &x;          //assigns p to address of x
    y = *p;         //value of y is now whatever p points to =1
    *p = 0;         //sets value of pointer and x to 0
    p = &z[0];      //p now points to z[0]
    
    p = &x;    
    //Every pointer points to a specific data type
    //pointer to void can hold any type of pointer but can't be dereferenced
    //The following 3 expressions increase the value of whatever [ point to by 1
    *p +=1;
    ++*p;
    (*p)++;         //() required because both + and * associate right to leftA

    int *q;
    q = p;          //makes pointer q point to whatever p points to

    int c = 66;
    int d = 99;
    int *a, *b;
    a = &c;
    b = &d;
    printf("Original value of a and b are: %d %d \n", *a, *b);
    pointerSwap ( a, b);
    printf("Swapped values are: %d %d \n", *a, *b);

    return 0;
}

//values do not change outside of the function
void regularSwap ( int a, int b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}


void pointerSwap ( int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}
