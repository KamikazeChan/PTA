#include <stdio.h>
#define MIN 0.000001
double f(double a3, double a2, double a1, double a0, double x)
{
    return a3*x*x*x+a2*x*x+a1*x+a0;
}
int main()
{
    double a3, a2, a1, a0, a, b, middle;
    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
    scanf("%lf %lf", &a, &b);
    while(f(a3, a2, a1,a0, a)*f(a3, a2, a1,a0, b)<0)
    {
        middle=f(a3, a2, a1,a0, (a+b)/2);
        if(middle<MIN && middle>-MIN|| (b-a)<0.001)
            break;
        else if(middle*f(a3, a2, a1,a0, a)<0)
            b=(a+b)/2;
        else
            a=(a+b)/2;
    }
    if(f(a3, a2, a1,a0, a)==0)
        printf("%.2f", a);
    else if(f(a3, a2, a1,a0, b)==0)
        printf("%.2f", b);
    else
        printf("%.2f", (a+b)/2);
    return 0;
}