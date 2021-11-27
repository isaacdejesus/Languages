#include <stdio.h>
#include <string.h>
//convert number to string

void itoa (int n, char s[]);
void reverse(char []);
int main()
{
    int i = 3335;
    char n [6];
    itoa(i, n);
    printf("%s \n", n);
    return 0;
}
//doesn't work. Returns int instead of string
void itoa(int n, char s[])
{
    int i, sign;

    if ((sign = n) <0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    }

    while ((n /=  10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
