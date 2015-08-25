#include <stdio.h>

int main()
{
    int n, a, b;
    scanf("%d", &n);
    a=n/16;
    b=n%16;
    a=a*10+b;
    printf("%d", a);
    return 0;
}