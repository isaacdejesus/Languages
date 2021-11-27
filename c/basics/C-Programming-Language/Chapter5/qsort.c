//Program sorts lines
//uses pointers to pass functions to functions
#include <stdio.h>
#include <string.h>

#define MAXLINES 5000
#define ALLOCSIZE 10000
static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;
char *alloc(int);
char *lineptr[MAXLINES];
int readlines(char *[], int);
void writelines( char *[], int);
void qsort(void *lineptr[], int, int, int(*comp)(void *, void *));
int numcmp(char *, char*);
int getLine( char [], int);
int main(int argc, char *argv[])
{
    int nlines;
    int numeric = 0;
    if(argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
    if((nlines = readlines(lineptr, MAXLINES)) >=0)
    {
        qsort((void **) lineptr, 0, nlines-1,
                (int (*)(void*,void*))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else 
    {
        printf("Error: input too big to sort \n");
        return 1;
    }
    return 0;
}

#define MAXLEN 1000
int getLine(char *, int);
char *alloc(int);

int readlines( char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while((len = getLine(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    while( nlines-- > 0)
        printf("%s\n", *lineptr++);
}

void qsort(void *v[], int left, int right, int (*comp)(void*, void*))
{
    int i, last;
    void swap(void *v[], int i, int j);
    if( left >= right)
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for( i = left + 1; i <= right; i++)
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last-1, comp);
    qsort(v, last+1, right, comp);
}

void swap(void *v[], int i, int j)
{
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

int getLine(char s[], int lim)
{
    int c, i;
    for( i = 0; i < lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;
    if(c == '\n')
    {
        s[i] = c;
        i++;
    }
    s[i] = '\0';
    return i;
}

char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocp >= n)
    {
        allocp +=n;
        return allocp - n;
    }
    else
        return 0;
}

int numcmp( char *s1, char *s2)
{
    double v1, v2;
    v1 = atof(s1);
    v2 = atof(s2);
    if (v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else 
        return 0;
}
