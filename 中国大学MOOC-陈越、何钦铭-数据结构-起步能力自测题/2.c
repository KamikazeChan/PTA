#include <stdio.h>
bool IsPrime(int n)
{
    if(n<2)
        return false;
    for(int i=2; i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}
int main()
{
    int n;
    int p[10000];
    scanf("%d", &n);
    int cnt=0;
    p[0]=2;
    for(int i=3, k=1; i<=n; i++)
    {
        if(IsPrime(i))
        {
            p[k++]=i;
            if(p[k-1]-p[k-2]==2)
                cnt++;
        }
    }
    printf("%d", cnt);
    return 0;
}