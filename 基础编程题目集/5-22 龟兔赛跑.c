#include <stdio.h>

int main()
{
    int T, s1=0, s2=0, t=0, cnt=0, flag=0;
    scanf("%d", &T);
    while (++t<=T)
    {
        s1+=3;
        cnt++;
        if(flag==1)
        {
            if(cnt==30)
            {
                cnt = 0;
                flag = 0;
            }
        }
        else
        {
            s2+=9;
            if(cnt==10)
            {
                cnt=0;
                if(s2>s1)
                    flag=1;
            }
        }
    }
    if(s1>s2)
        printf("@_@ %d", s1);
    else if(s1<s2)
        printf("^_^ %d", s2);
    else
        printf("-_- %d", s1);
    return 0;
}