#include <stdio.h>

int main()
{
    int N, U, D, cnt=0, h=0;
    scanf("%d %d %d", &N, &U, &D);
    while(h+U<N)
    {
        h+=(U-D);
        cnt+=2;
    }
    printf("%d",cnt+1);
    return 0;
}