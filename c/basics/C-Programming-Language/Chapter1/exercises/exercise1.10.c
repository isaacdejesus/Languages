/*copy input to output replacing tab by \t, each backspace by \b and backslash by // */
#include <stdio.h>
main()
{
    int c;

    while ((c = getchar()) != EOF)
        if(c == '\t')
            printf("\\t");
        else if (c == '\b')
            printf("\\b");
        else if (c == '\\')
            printf("\\\\");
        else
            putchar(c);
}

