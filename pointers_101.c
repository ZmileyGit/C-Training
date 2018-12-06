#include <stdio.h>

void print_values(int x,int y,int *q,int *p);

int main(){
    int x = 17;
    int y = 18;
    int z[10];
    int *p;
    int *q;

    p = &x;
    q = &y;
    print_values(x,y,q,p);

    *q = *p;
    print_values(x,y,q,p);
    *p = 7;
    print_values(x,y,q,p);

    z[0] = 19;
    q = &z[0];
    printf("%d\n",*q);
    z[3] = 45;
    q+=3;
    printf("%d\n",*q);

    return 0;
}

void print_values(int x,int y,int *q,int *p){
    printf("Values\n");
    printf("X:%d Y:%d >P:%u =P:%d >Q:%u =Q:%d\n",x,y,p,*p,q,*q);
}