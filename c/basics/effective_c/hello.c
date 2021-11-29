#include <stdio.h>  //io functions such as puts
#include <stdlib.h> //utility functions such as EXIT_SUCCESS
//includes are preprocessor directives

int main(void)   //void indicates function doesn't take arguments
{

    //puts is an improved version of printf
    //will evaluate to EOF if failed to print
    //EXIT_SUCCESS evals to 0
    if(puts("Hello, world from modern C") == EOF) //adds \n at the end of the string
        return EXIT_FAILURE;

    //printf can still be used to format output
    printf("%s\n", "Hello, world using printf");
    return EXIT_SUCCESS;

}
