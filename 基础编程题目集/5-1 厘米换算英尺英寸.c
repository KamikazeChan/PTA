#include <stdio.h>

int main()
{
    int cm, foot, inch;
    scanf("%d", &cm);
    foot=(int)(cm/30.48);
    inch=(int)((cm/30.48-foot)*12);
    printf("%d %d", foot, inch);
    return 0;
}