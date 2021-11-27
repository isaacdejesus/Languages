//Prints lines 80+
#include <stdio.h>
#define MAXLINE 1000
int getLine(char [], int );
void Reverse(char s[]);
int main()
{
    char line[MAXLINE];

    while(getLine(line, MAXLINE) > 0)
        Reverse(line);
            printf("%s", line);
    return 0;
}

//read a line into s, returns length
int getLine(char s[], int lim)
{
    int c, i, j;
    j =0;

    for (i =0 ; (c = getchar()) !=EOF && c != '\n'; ++i)
        if( i < lim -2)
        {
            s[j] = c;
            ++j;
        }
        if( c == '\n')
        {
            s[j] = c;
            ++j;
            ++i;
        }
        s[j] = '\0';
        return i;
}

void Reverse( char s[])
{
    int i, j;
    char temp;
    i = 0;
    while(s[i] != '\0')
        ++i;
    --i;
    if(s[i] == '\n')
        --i;
    j = 0;
    while(j < i)
    {
        temp = s[j];
        s[j] = s[i];
        s[i] = temp;
        --i;
        ++j;
    }
}


