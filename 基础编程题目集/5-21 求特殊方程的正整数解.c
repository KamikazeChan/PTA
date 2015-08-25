#include <stdio.h>

int main()
{
    int n, flag=0;
    scanf("%d", &n);
    for(int x=1; x*x<n; x++)
    {
        for(int y=x; y*y<=n; y++)
            if(x*x+y*y==n)
            {
                if(flag==1)
                    printf("\n");
                printf("%d %d", x, y);
                flag=1;
            }
    }
    if(flag==0)
        printf("No Solution");
    return 0;
}