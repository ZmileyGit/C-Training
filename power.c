#include <stdio.h>

int power(int base,int exponent);


int main(){
    for(int count=0;count<10;++count){
        printf("%d^%d: %5d | %d^%d %5d\n",2,count,power(2,count),-3,count,power(-3,count));
    }
    return 0;
}

int power(int n,int m){
    int result = 1;
    for(int count=0;count<m;++count){
        result*=n;
    }
    return result;
}