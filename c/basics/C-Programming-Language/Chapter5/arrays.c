#include <stdio.h>
//read mid of page 99. It is confusing
//
int strLen(char *s);
int main()
{
    //defines block of 10 constinuos objects named:
    //arr[0], arr[1]...arr[9]
    int arr [10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //individual object can be accessed a[i], where i is ith elemenmt of array
    int *p;
    p = &arr[0];    //sets pointer p to address of first element of arr
    p = arr;        //same as above since name of array points to first element
    int x;
    x = *p;         //copy content of arr[0] to x
    p + 1;           //points to the next elementA
    printf("p + 1 points to arr[1] which is: %d \n", *p+1);
    p + 4;          //points to the 4th element
    printf("p + 4 points to arr[5] which is: %d \n", *p+4);
    p - 4;          //points back by 4 elements
    printf("p - 4 points to arr[1] which is: %d \n", *p-4);
   

    //char * is the preferred way to define formal parameters for arrays
    //because we can pass a string, constant array or pointer 
    char c_array [] = "hello, i am potato man"; 
    char *parray = &c_array[0]; 
    printf("Size of the input string 'hello' is: %d \n", strLen("hello"));
    printf("Size of the input string %s is: %d \n", c_array, strLen(c_array));
    printf("Size of the input string %s is: %d \n", c_array, strLen(parray));

    //can also pass a subarray to a function that expects an array
    //&arr[2] or a + 2 will pass subarray starting at arr[2]
    printf("Size of sub-arr string starting at index 5 is: %d \n", strLen(parray + 5));
    printf("Size of sub-arr string starting at index 15 is: %d \n", strLen(&c_array[15]));
    return 0;
}

//formal parameters for a function can be char [] or char *
int strLen(char *s)
{
    int n;

    for(n = 0; *s != '\0'; s++)
        n++;
    return n;
}
