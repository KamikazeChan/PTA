#include <stdio.h>

int main()
{
    char a[30], b[30], c[30];
    char ch;
    int i=0, m, k, carry=0;

    while((ch=getchar())!='\n')
        a[i++]=ch;
    for(int j=0; j<i; j++)
        b[j]=a[i-1-j];

    for(int j=0; j<i; j++)
    {
        m=(b[j]-'0')*2+carry;
        b[j]='0'+m%10;
        carry=m/10;
    }
    b[i]='0'+carry;
    for(int j=0; j<=i; j++)
        c[j]=b[j];
    if(b[i]!='0')
        printf("No\n%c", b[i]);
    else
    {
        for(k=0; k<i; k++)
        {
            for(m=0; m<i; m++)
            {
                if(a[k]==b[m])
                {
                    b[m]='\0';
                    break;
                }
            }
            if(m==i)
            {
                printf("No\n");
                break;
            }
        }
        if(m!=i)
            printf("Yes\n");
    }
    for(int j=i-1; j>=0; j--)
        printf("%c", c[j]);

    return 0;
}