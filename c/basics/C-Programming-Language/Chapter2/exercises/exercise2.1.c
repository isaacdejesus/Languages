//determine ranges
#include <stdio.h>

int main()
{
    printf("Signed char min = %d\n", -(char)((unsigned char) ~0 >> 1));
    printf("Signed char max = %d\n", (char)((unsigned char) ~0 >> 1));
    printf("Signed short min = %d\n", -(short)((unsigned short) ~0 >> 1));
    printf("Signed short max = %d\n", (short)((unsigned short) ~0 >> 1));
    printf("Signed int min = %d\n", -(int)((unsigned int) ~0 >> 1));
    printf("Signed int max = %d\n", (int)((unsigned int) ~0 >> 1));
    printf("Signed long min = %d\n", -(long)((unsigned char) ~0 >> 1));
    printf("Signed long max = %d\n", (long)((unsigned char) ~0 >> 1));

    printf("unsigned char max = %u\n", (unsigned char) ~0);
    printf("unsigned short max = %u\n", (unsigned short) ~0);
    printf("unsigned int max = %u\n", (unsigned int) ~0);
    printf("unsigned long max = %u\n", (unsigned long) ~0);

    return 0;
}

