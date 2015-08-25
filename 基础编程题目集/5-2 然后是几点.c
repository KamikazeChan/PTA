#include <stdio.h>

int main()
{
    int start, stop, interval, hour, minute;
    scanf("%d %d", &start, &interval);

    stop=start%100+start/100*60+interval;
    hour=stop/60;
    minute=stop%60;
    stop=hour*100+minute;
    printf("%d", stop);
    return 0;
}