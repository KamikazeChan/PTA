#include <stdio.h>
#include <string.h>
int lcm(int a, int b)
{
    for(int i=a; i<=a*b; i++)
        if(i%a==0 && i%b==0)
            return i;
}
int gcd(int a, int b)
{
    int GCD=1;
    for(int i=1; i<=a && i<=b;i++)
    {
        if(a%i==0 && b%i==0 && i>GCD)
            GCD=i;
    }
    return GCD;
}
int main()
{
    int a, b, c, d;
    int l, m, g;
    scanf("%d/%d %d/%d", &a, &b, &c, &d);
    l=lcm(b,d);
    m=l/b*a+l/d*c;
    if(m<0)
    {
        printf("-");
        m=-m;
    }
    g=gcd(m, l);
    m/=g;
    l/=g;
    if(m%l==0)
        printf("%d", m/l);
    else
        printf("%d/%d", m, l);
    return 0;
}