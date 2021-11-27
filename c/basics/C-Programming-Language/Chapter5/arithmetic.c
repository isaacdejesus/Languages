#include <stdio.h>
#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc( int );
void afree( char *p);
int strLen( char *);
int main()
{
    int arr [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int *p = &arr[0];
    //p++ moves pointer to next element
    //p+=i moves pointer by i elements 
    printf("p originally points to %d \n", *p);
    printf("p+=5 points to %d \n", *p+=5);

    //alloc(n) returns pointer to n consecutive positions
    //afree(p) releases memory to be used later
    //standard lib has functions malloc and free
    //alloc uses a pointer to keep track of the next available bit ot memory
    //returns errors if there isn't enough memory left to accomodate requested allocation
    //relations: ==, !=, >, <, >= work if both pointers point to same array
    //p > q works if both pointers point to same array
    //Ints can be added or subs from pointers to move by that many elements
    //p + n moves pointer by n elements
    //
    return 0;
}

char *alloc(int n)
{   
    if(allocbuf + ALLOCSIZE - allocp >= n)
    {   
        allocp += n;
        return allocp - n;
    }
    else
        return 0;
}

void  afree( char *p)
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
//new version uses pointer artihmetic to calc string length
int strLen( char *s)
{
    char *p = s;
    while ( *p != '\0')
        p++;
    return p - s;
}
