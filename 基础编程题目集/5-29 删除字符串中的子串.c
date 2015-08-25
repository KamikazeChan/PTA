#include <stdio.h>
#include <string.h>
int main()
{
    char s1[81], s2[81];
    int l1, l2, i, p;
    char *j;
    gets(s1);
    gets(s2);

    l1=strlen(s1);
    l2=strlen(s2);
    j=strstr(s1, s2);
    while(j!=NULL)
    {
        p=j-s1;
        l1-=l2;
        for(i=p; i<l1; i++)
            s1[i]=s1[i+l2];
        s1[l1]='\0';
        j=strstr(s1, s2);
    }
    printf("%s", s1);
    return 0;
}