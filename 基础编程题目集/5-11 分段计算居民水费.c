 5-5.c
#include <stdio.h>

int main()
{
    int a;
    scanf("%d", &a);
    if(a<=15)
        printf("%.2f", (float)4*a/3);
    else
        printf("%.2f", 2.5*a-17.5);
    return 0;
}