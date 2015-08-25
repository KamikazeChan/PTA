#include <stdio.h>

int main()
{
    char a[10]={'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
    char b[8]={'Y', 'Q', 'B', 'S', 'W', 'Q', 'B', 'S'};
    char c[10];
    char ch;
    int i=0, flag=0;
    while((ch=getchar())!='\n')
    {
        c[i++]=ch;
    }
    if(i==1 && c[0]=='0')
    {
        printf("a");
        return 0;
    }
    for(int j=0;j<i;j++)
    {
        if(c[j]!='0' && flag==1)
        {
            flag = 0;
            if(9-i+j!=1 && 9-i+j!=5)
                printf("a");
        }
        if(c[j]=='0') {
            if(9-i+j==0 || 9-i+j==4)
                printf("%c", b[9-i+j]);
            flag = 1;
            continue;
        }
        printf("%c", a[c[j]-'0']);
        if(c[j]!='0' && j<i-1)
            printf("%c", b[9-i+j]);
    }

    return 0;
}