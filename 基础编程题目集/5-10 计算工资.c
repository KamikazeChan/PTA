#include <stdio.h>

int main()
{
    int a, b;
    scanf("%d %d", &a, &b);
    if(a>=5)
        if(b>40)
            printf("%.2f", (float)50*((b-40)*0.5+b));
        else
            printf("%.2f", (float)50*b);
    else
        if(b>40)
            printf("%.2f", (float)30*((b-40)*0.5+b));
        else
            printf("%.2f", (float)30*b);
    return 0;
}