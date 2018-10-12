#include <stdio.h>

unsigned int setbits(unsigned int word, int to, int length, int from);
unsigned int getbits(unsigned int word, int position, int length);

int main(){
    printf("%d\n",getbits(92U,4,3));
    return 0;
}

unsigned int setbits(unsigned int word, int to, int length, int from){
    return 0;
}

unsigned int getbits(unsigned int word, int position, int length){
    return (word >> (position-(length-1))) & ~(~0 << length);
}