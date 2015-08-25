#include <stdio.h>

int main()
{
    float open, close, high, low;
    int flag1=0, flag2=0;
    scanf("%f %f %f %f", &open, &high, &low, &close);
    if(close<open)
        printf("BW-Solid");
    else if(close>open)
        printf("R-Hollow");
    else if(close==open)
        printf("R-Cross");
    if(low <open && low < close)
        flag1=1;
    if(high>open && high>close)
        flag2=1;
    if(flag1+flag2==2)
        printf(" with Lower Shadow and Upper Shadow");
    else if(flag1==1)
        printf(" with Lower Shadow");
    else if(flag2==1)
        printf(" with Upper Shadow");
    return 0;
}