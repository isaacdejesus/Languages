#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define HASHSIZE 101

struct nlist {
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

unsigned hash(char *s)
{
    unsigned hashval;
    for( hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s)
{
    struct nlist *np;
    for( np = hashtab[hash(s)]; np != NULL; np = np->next)
        if(strcmp(s, np->name) == 0)
            return np;
    return NULL;
}

char *strDup(char *s)
{
    char *p;
    p = (char *) malloc(strlen(s) + 1);
    if (p != NULL)
        strcpy(p, s);
    return p;
}
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if((np = lookup(name)) == NULL)
    {
        np = (struct nlist *) malloc(sizeof(*np));
        if( np == NULL || (np->name = strDup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    }
    else
        free((void *) np->defn);
    if((np->defn = strDup(defn)) == NULL)
        return NULL;
    return np;
}


//will fix later. Not sure how to test the functions`
int main()
{
    struct nlist records;
    records.install("one", "uno");
    return 0;
}
