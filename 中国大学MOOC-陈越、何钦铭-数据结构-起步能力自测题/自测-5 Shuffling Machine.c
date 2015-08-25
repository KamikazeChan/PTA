#include <stdio.h>
#include <memory.h>
int main()
{
    int n;
    int a[54], order[54], temp[54];
    scanf("%d", &n);
    for(int i=0; i<54; i++)
    {
        scanf("%d", &order[i]);
        a[i]=i;
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<54; j++)
            temp[order[j]-1]=a[j];
        memcpy(a, temp, 54* sizeof(int));
    }
    for(int i=0; i<54; i++)
    {
        if(a[i]==52)
            printf("J1");
        else if(a[i]==53)
            printf("J2");
        else if(a[i]<13)
            printf("S%d", a[i]+1);
        else if(a[i]>=13 && a[i]<26)
            printf("H%d", a[i]-12);
        else if(a[i]>=26 && a[i]<39)
            printf("C%d", a[i]-25);
        else if(a[i]>=39 && a[i]<52)
            printf("D%d", a[i]-38);
        if(i<53)
            printf(" ");
    }
    return 0;
}