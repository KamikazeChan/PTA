#include <stdio.h>

int main()
{
    int a,b;
    scanf("%d %d", &a, &b);
    int cnt=0, sum=0;
    for(int i=a; i<=b; i++)
    {
        printf("%5d", i);
        cnt++;
        sum+=i;
        if(cnt==5)
        {
            cnt=0;
            printf("\n");
        }
    }
    if(cnt!=0)
        printf("\n");
    printf("Sum = %d", sum);
    return 0;
}