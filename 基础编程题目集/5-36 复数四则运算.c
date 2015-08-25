#include <stdio.h>
typedef struct {
    float r;
    float v;
}Complex;


int main()
{
    Complex cpx[6];
    scanf("%f%f%f%f", &cpx[0].r, &cpx[0].v, &cpx[1].r, &cpx[1].v);

    cpx[2].r=cpx[0].r+cpx[1].r;
    cpx[2].v=cpx[0].v+cpx[1].v;

    cpx[3].r=cpx[0].r-cpx[1].r;
    cpx[3].v=cpx[0].v-cpx[1].v;

    cpx[4].r=cpx[0].r*cpx[1].r-cpx[0].v*cpx[1].v;
    cpx[4].v=cpx[0].r*cpx[1].v+cpx[0].v*cpx[1].r;

    cpx[5].r=(cpx[0].r*cpx[1].r+cpx[0].v*cpx[1].v)/(cpx[1].r*cpx[1].r+cpx[1].v*cpx[1].v);
    cpx[5].v=(cpx[0].v*cpx[1].r-cpx[0].r*cpx[1].v)/(cpx[1].r*cpx[1].r+cpx[1].v*cpx[1].v);

    char op[4]={'+', '-', '*', '/'};

    for(int i=0; i<4; i++)
    {
        printf("(%.1f", cpx[0].r);
        if(cpx[0].v>=0)
            printf("+");
        printf("%.1fi) %c (%.1f", cpx[0].v, op[i], cpx[1].r);
        if(cpx[1].v>=0)
            printf("+");
        printf("%.1fi) = ", cpx[1].v);
        if(cpx[2+i].r>=0.1 || cpx[2+i].r<=-0.1) {
            printf("%.1f", cpx[2 + i].r);
            if (cpx[2 + i].v >= 0.1)
                printf("+");
        }
        else if(cpx[2+i].v>-0.1 && cpx[2+i].v<0.1){
            printf("0.0\n");
            continue;}
        if (cpx[2 + i].v >= 0.1 || cpx[2 + i].v <= -0.1)
            printf("%.1fi\n", cpx[2 + i].v);
        else
            printf("\n");
    }

    return 0;
}