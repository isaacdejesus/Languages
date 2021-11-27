#include <stdio.h>

void squeeze(char [], int);
void strCat( char [], char []);
int main()
{
    //++ and -- can be used as prefix or postfix op
    //Testing squueze function
    char str [] = "Memberssssss";
    printf("Original string is: %s\n", str);
    squeeze(str, 'm');
    printf("Resulting string after squeeze is: %s \n", str);

    //Testing the strcat function
    char longstr [1000] = "hello";
    char small1 [] = "Iam";
    char small2 [] = "small";

    strCat(longstr, small1);
    strCat(longstr, small2);
    printf("Resulting string is: %s \n", longstr);
    return 0;
}

//Removes occurrences of c in s
void squeeze(char s[], int c)
{
    int i, j;

    for ( i = j = 0; s[i] != '\0'; i++)
        if (s[i] != c)
            s[j++] = s[i];
    s[j] = '\0';
}
//concat t at end of s
void strCat( char s[], char t[])
{
    int i, j;
    i = j = 0;
    while (s[i] != '\0')
    i++;
    while ((s[i++] = t[j++]) != '\0')
     ;   
}
