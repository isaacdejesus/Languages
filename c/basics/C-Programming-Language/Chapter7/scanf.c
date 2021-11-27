#include <stdio.h>
//all arguments to scanf need to be pointers

int main()
{
    while(getline(line, sizeof(line)) > 0)
    {
        if(sscanf(line, "%d %s %d", &day, monthname, &year) == 3)
            printf("valid: %s\n", line);
        else if(sscanf(line, "%d/%d/%d", &month, &day, &year) == 3)
            printf("valid: %s\n", line);
        else 
            printf("invalid: %s\n", line);
    }
}

