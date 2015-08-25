#include<stdio.h>
struct rational
    {
        int a;
        int b;
    };
int main()
{
    
    rational x, r[110];
    int i, n;
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d/%d", &r[i].a, &r[i].b);
    }
    x.a = 0;
    x.b = 1;
    for(i = 0; i < n; i++)
    {
        x.a = x.a * r[i].b + x.b * r[i].a;
        x.b *= r[i].b;
    }
    x.b *= n;
    int temp, h, l;
    h = x.a > x.b ? x.a : x.b;
    l = x.a < x.b ? x.a : x.b;
    while(l)
    {
        temp = h % l;
        h = l;
        l = temp;
    }
    if(h != 0)
    {
        x.a /= h;
        x.b /= h;
    }
    if(x.a == 0)
        printf("%d\n", x.a);
    else if(x.b == 1)
        printf("%d\n", x.a);
    else
        printf("%d/%d\n", x.a, x.b);
    return 0;
}