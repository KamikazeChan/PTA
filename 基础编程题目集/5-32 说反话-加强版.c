#include <stdio.h>
#include <string.h>

int main()
{
    char s[500001];
    char *p,*pp[250001];
    long i=0,j;
    gets(s);
    p=strtok(s," ");
    pp[0]=p;
    i++;
    p=strtok(NULL," ");
    while(p)
    {
        pp[i++]=p;
        p=strtok(NULL," ");
    }
    for(j=i-1; j>=0; j--)
    {
        if(pp[j])
        {
            if(j==0)
            {
                printf("%s",pp[j]);
            }
            else
            {
                printf("%s ",pp[j]);
            }
        }

    }
    return 0;
}
