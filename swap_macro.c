#include <stdio.h>

#define swap(t,x,y) t _temp = x;x = y;y = _temp;

int main(){
    int nano = 17;
    int micro = 18;
    printf("%d %d\n",nano,micro);
    swap(int,nano,micro);
    printf("%d %d\n",nano,micro);
}