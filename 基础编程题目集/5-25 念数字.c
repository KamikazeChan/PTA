#include <stdio.h>

int main()
{
    char a[20][10]={"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    char ch;
    int flag=0;
    while((ch=getchar())!='\n')
    {
        if(flag==1)
            printf(" ");
        flag=1;
        if(ch=='-')
            printf("fu");
        else
            printf("%s", a[ch-'0']);
    }
    return 0;
}