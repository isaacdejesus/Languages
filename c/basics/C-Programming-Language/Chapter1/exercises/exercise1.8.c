//count blanks, tabs and new lines
#include <stdio.h>
main()
{
    int c, blanks, tabs, newLines;
    blanks = tabs = newLines = 0;
    
    while ((c =  getchar()) != EOF)
        if(c == ' ')
            blanks++;
        else if (c == '\t')
            tabs++;
        else if (c == '\n')
            newLines++;
    printf("Blanks tabs newLines\n");
    printf("%6d %4d %8d\n", blanks, tabs, newLines);
}
