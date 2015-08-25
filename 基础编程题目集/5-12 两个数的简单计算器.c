ECHO 处于打开状态。
#include <stdio.h>

int main()
{
    int a, b;
    char ch;
    scanf("%d %c %d", &a, &ch, &b);
    switch(ch) {
        case '+':
            printf("%d", a + b);
            break;
        case '-':
            printf("%d", a - b);
            break;
        case '*':
            printf("%d", a * b);
            break;
        case '/':
            printf("%d", a / b);
            break;
        case '%':
            printf("%d", a % b);
            break;
        default:
            printf("ERROR");
    }
    return 0;
}