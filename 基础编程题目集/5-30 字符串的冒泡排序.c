#include <stdio.h>
#include <string.h>
int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    int i;
    char temp[12];
    char str[100][12];
    for(i=0;i<n;i++)
    {
        scanf("%s", str[i]);
    }
    for(i=0;i<k;i++)
        for(int j=0;j<n-i-1;j++)
            if(strcmp(str[j], str[j+1])>0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j+1]);
                strcpy(str[j+1], temp);
            }
    for(i=0;i<n;i++) {
        printf("%s", str[i]);
        if(i<n-1)
            printf("\n");
    }
    return 0;
}