#include <stdio.h>

int main()
{
    int n;
    int i=1, k=3;
    char ch;
    scanf("%d %c", &n, &ch);

    if(n>=1 && n <7)
    {
        printf("%c\n%d", ch, n - 1);
        return 0;
    }
    n-=1;
    while(n-k*2>=0)
    {
        n-=k*2;
        k+=2;
        i++;
    }
    for(int j=0; j<i; j++) {
        for (int l = 0; l < j; l++)
            printf(" ");
        for (int l = 0; l < k-2 - j * 2; l++)
            printf("%c", ch);
        printf("\n");
    }
    for(int j=i-2; j>=0; j--)
    {
        for (int l = 0; l < j; l++)
            printf(" ");
        for (int l = 0; l < k-2 - j * 2; l++)
            printf("%c", ch);
        printf("\n");
    }
    printf("%d", n);
    return 0;
}