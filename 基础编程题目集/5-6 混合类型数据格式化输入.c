#include <stdio.h>

int main()
{
    double d1, d2;
    char ch;
    int a;
    scanf("%lf %d %c %lf", &d1, &a, &ch, &d2);
    printf("%c %d %.2f %.2f", ch, a, d1, d2);
    return 0;
}