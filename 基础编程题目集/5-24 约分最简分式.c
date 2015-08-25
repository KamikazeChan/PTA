#include <stdio.h>

int main()
{
    int a,b,temp,l,s;
    scanf("%d/%d", &a, &b);
	l=a>b?a:b;
	s=a>b?b:a;
    while(s!=0)
    {
        temp=l%s;
		l=s;
		s=temp;
    }
	if(l!=0)
	{
		a/=l;
		b/=l;
	}

    printf("%d/%d", a, b);
    return 0;
}