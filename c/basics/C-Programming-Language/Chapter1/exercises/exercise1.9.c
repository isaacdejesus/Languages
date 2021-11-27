//copy input to output replacing strings of 1+ blanks by a single blank
#include <stdio.h>

#define NONBLANK 'a'

main()
{
    int c, lastc;

    lastc = NONBLANK;

    while ((c=getchar()) != EOF)
    {
        if ( c != ' ' || lastc != ' ')
            putchar(c);
        lastc = c;
    }
}
