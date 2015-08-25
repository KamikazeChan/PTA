#include <stdio.h>

int main()
{
    char ch;
    int cnt=1;
    int flag=1;

    while((ch=getchar())==' ')
        ;
    if(ch=='.')
    {
        return 0;
    }
    while((ch=getchar())!='.')
    {
        if(ch==' ')
        {
            flag = 0;
            continue;
        }
        cnt++;
        if(flag==0)
        {
            flag=1;
            printf("%d ", cnt-1);
            cnt=1;
        }
    }
    printf("%d", cnt);
    return 0;
}