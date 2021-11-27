//typedef allows you to rename new datatypes

typedef int Legth;

//then we can declare new vars
Legth len, maxlen;      //these vars will be of type in

typedef char *String;

String p, lineptr[10000], alloc(int);
int strcmp(String, String);
p = (String) malloc(100);

//all of the above String are replacements for char *
