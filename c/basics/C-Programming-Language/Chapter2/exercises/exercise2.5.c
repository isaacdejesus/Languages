//return first location in string s1 where any char from s2 occurs.
//return -1 if no matches
#include <stdio.h>
int any (char [], char []);


int main()
{   
    char str1 [] = "Hhiillo";
    char str2 [] = "hi";

    printf("%d\n", any(str1, str2));
    return 0;
}
int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
        for (j =0 ; s2[j] != '\0'; j++)
            if(s1[i] == s2[j])
                return i;
    return -1;
}
