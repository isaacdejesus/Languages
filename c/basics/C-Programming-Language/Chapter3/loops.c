#include <stdio.h>
#include <ctype.h>
#include <string.h>


//convert string to int
int atoi(char s[]);
int Atoi(char s[]);
int lower(int);
void shellsort (int [], int );
void reverse(char []);
int main()
{
    char str [] = "hello";
    printf("%d \n", Atoi(str));
    char k = 'K';
    printf("%c \n", lower(k));
    reverse(str);
    printf("%s \n", str);
     return 0;
}


//Supposed to convert string s to int. Doesn't work
int atoi(char s[])
{
    int i, n, sign;

    for (i =0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if (s[i] == '+' || s[i] == '-')
        i++;
    for (n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    return sign * n;
}

//From chapter 2
int Atoi(char s[])
{
    int i, n;
    n = 0;
    for (i = 0; s[i] >= '0' && s[i] <= '9'; ++i)
        n = 10 * n + (s[i] - '0');
    return n;
}
//conver c to lower case
int lower (int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else 
        return c;
}

//shellsort
void shellsort (int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap >0; gap /=2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j] > v[j+gap]; j-=gap)
            {
                temp = v[j];
                v[j] = v[j + gap];
                v[j + gap] = temp;
            }
}
//supposed to reverse string. Doesn't really work
void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++,  j --)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}
