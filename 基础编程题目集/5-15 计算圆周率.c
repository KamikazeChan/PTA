#include <stdio.h>

int main()
{
    float a;
    scanf("%f", &a);
    int n=0;
    float up=1.0, down=1.0, rst;
    rst=up/down;
    while((up/down)>=a)
    {
        n++;
        up*=n;
        down*=(2*n+1);
        rst+=up/down;
    }
    rst*=2;
    printf("%.6f",rst);
    return 0;
}