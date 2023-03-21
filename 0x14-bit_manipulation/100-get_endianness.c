#include <stdio.h>
#include <limits.h>
#include "main.h"

int get_endianness(void)
{
    int num = 1;
    char *ptr = (char *) &num;

    return (*ptr == 1) ? 1 : 0;
}
int main(void)
{
    int endian = get_endianness();

    if (endian == 1)
    {
        printf("Little Endian\n");
    }
    else
    {
        printf("Big Endian\n");
    }
    return (0);
}
