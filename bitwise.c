#include <stdio.h>

unsigned int setbits(unsigned int word, int to, int length, int from);
unsigned int getbits(unsigned int word, int position, int length);
unsigned int invert(unsigned int word, int position, int length);
unsigned int rightrot(unsigned int word,int radius);
short intlen(void);

int main(){
    printf("%u\n",getbits(92U,4,3));
    printf("%u\n",setbits(237U,8,4,15));
    printf("%u\n",invert(237U,8,4));
    printf("%u\n",rightrot(5171U,8));
    return 0;
}

unsigned int setbits(unsigned int word, int to, int length, int from){
    unsigned int to_mask = ((~0U) << (to+1)) ^ ((~0U) << (to + 1 - length));
    unsigned int from_mask = ((~0U) << (from + length)) ^ ((~0U) << from);
    unsigned int source = (word & from_mask) >> (from - to + length - 1);
    return (word & ~to_mask) | source;
}

unsigned int invert(unsigned int word, int position, int length){
    unsigned int mask = ((~0U) << (position + 1)) ^ ((~0U) << (position + 1 - length));
    return (~(word & mask) & mask) | (word & ~mask);
}

unsigned int rightrot(unsigned int word,int radius){
    return (word >> radius) | ((word & ~(~0 << (radius + 1))) << (intlen() - radius));
}

short intlen(void){
    unsigned int simple = 1U;
    short size;
    for(size = 0;simple > 0;++size){
        simple <<= 1;
    }
    return size;
}

unsigned int getbits(unsigned int word, int position, int length){
    return (word >> (position + 1 - length)) & ~(~0 << length);
}