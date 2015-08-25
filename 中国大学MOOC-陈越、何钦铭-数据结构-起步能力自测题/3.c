#include <stdio.h>

int main()
{
    int a[101], b[101];

    int n, m;
    scanf("%d %d", &n, &m);
    for(int i=0; i<n; i++)
        scanf("%d", &a[i]);
    m%=n;
    for(int i=0; i+m<n; i++)
        b[i+m]=a[i];
    for(int i=0; i<m; i++)
        b[i]=a[i+n-m];
    for(int i=0; i<n; i++)
    {
        printf("%d", b[i]);
        if(i<n-1)
            printf(" ");
    }
    return 0;
}