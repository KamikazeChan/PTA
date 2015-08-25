#include <stdio.h>
#include <string.h>
int main()
{
    char str1[101];
    char str2[101];
    int n, l;
    gets(str1);
    scanf("%d", &n);
    l=strlen(str1);
    n%=l;
    for(int i=0; i+n<l; i++)
        str2[i]=str1[i+n];
    for(int i=l-n; i<l; i++)
        str2[i]=str1[i+n-l];
    str2[l]='\0';
    printf("%s", str2);
    return 0;
}