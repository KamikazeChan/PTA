#include <stdio.h>
#include <string.h>

typedef struct {
    char name[15];
    char date[15];
    char gender;
    char phone[20];
    char mobile[20];
}Info;

int main()
{
    int n;
    int i;
    int k;
    int a;
    Info info[10];
    scanf("%d", &n);
    getchar();
    for(i=0;i<n;i++)
        scanf("%s %s %c %s %s", info[i].name, info[i].date, &info[i].gender, info[i].phone, info[i].mobile);
    scanf("%d", &k);
    for(i=0;i<k;i++) {
        scanf("%d", &a);
        if (a < n && a>=0)
            printf("%s %s %s %c %s\n", info[a].name, info[a].phone, info[a].mobile, info[a].gender, info[a].date);
        else
            printf("Not Found\n");
    }
    return 0;
}