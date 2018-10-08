#include <stdio.h>

int main(){
    int w,y;
    w=0;
    y=0;
    while((w+=1)<10 || (y+=2)<20){
        printf("%d %d\n",w,y);
    }
}