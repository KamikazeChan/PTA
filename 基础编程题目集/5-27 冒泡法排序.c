#include <stdio.h>

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int i, temp;
    int a[100];
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }
    for(i=0;i<k;i++)
        for(int j=0;j<n-i-1;j++)
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
    for(i=0;i<n;i++) {
        printf("%d", a[i]);
        if(i<n-1)
            printf(" ");
    }
    return 0;
}