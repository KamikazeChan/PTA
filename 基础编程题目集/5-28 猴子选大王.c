#include <stdio.h>

int main()
{
    int n;
    int a[1002]={0};
    scanf("%d", &n);
    int last=0;
    int cur=1;
    int cnt=1;

    for(int i=2;i<=n+1;i++)
    {
        if(i==n+1)
            i=1;
        if(last==cur)
            break;
        if(a[i]==1)
            continue;
        last=cur;
        cur=i;
        cnt++;
        if(cnt==3)
        {
            cnt=0;
            a[i]=1;
        }
    }
    printf("%d", cur);
    return 0;
}