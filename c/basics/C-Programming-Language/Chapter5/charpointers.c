#include <stdio.h>
void strCpy( char *, char *);
void strcopypointer( char *, char *);
int strCmp( char *, char *);
int strCmppointer( char *, char *);
int main()
{
   //This is a string constant 
    // printf("hello, world"); 
    char amessage[] = "now is the time";
    char *pmessage = "now is the time";
    //contants of amessage can be modifies
    //contents of pmessage can't be modified
    // *--p;        decrements p will decrement by one element then fetch value stored in p
    //
    return 0;
}

void strCpy( char *s, char *t)
{
    int i = 0;

    while((s[i] = t[i]) != '\0')
        i++;
}

void strcpypointer( char *s, char *t)
{
    while((*s++ = *t++) != '\0')
        ;
}

int strCmp( char *s, char *t)
{
    int i;
    for( i =0; s[i] == t[i]; i++)
        if( s[i] == '\0')
            return 0;
    return s[i] - t[i];
}

int strCmppointer( char *s, char *t)
{
    for( ; *s == *t; s++, t++)
        if( *s == '\0')
            return 0;
    return *s - *t;
}
