#include <stdio.h>
int main()
{
    //arrays can be ini at declaration with a list of values enclpsed 
    //in {}, separated by commands
    //first value is number of strings in 2d array.
    //second value is max lenght of strings
    char daysOfWeek [7][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int Numbs [] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    //two ways of stringing
    char pattern [] = "ould";
    char Pattern [] = { 'o', 'u', 'l', 'd', '\0'};

    printf("Days of the week are: ");
    for ( int i =0 ; i < 7 ; i ++)
        printf("%s ", daysOfWeek[i]);
    printf("\n");   
    printf("pattern is: %s \n", pattern);
    printf("Pattern is: %s \n", Pattern);
    return 0;
}

//if not ini external and static vars are set to 0
//automatic and register vars are set to grabage
// external and static var need to be  be ini with a constant value
// automatic and register vars don't have constant restriction
