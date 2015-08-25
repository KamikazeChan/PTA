#include <stdio.h>

int main()
{
    int a[4];
    int i,j,k,cnt=0;
    scanf("%d", &a[0]);
    for(i=1;i<4;i++)
        a[i]=a[0]+i;
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(j==i)
                continue;
            for(k=0;k<4;k++)
            {
                if(k==j || k==i)
                    continue;
                cnt++;
                if(cnt==6)
                    cnt=0;
                printf("%d%d%d",a[i],a[j],a[k]);
                if(cnt!=0)
                    printf(" ");
                else
                    printf("\n");
            }
        }
    }
    return 0;
}