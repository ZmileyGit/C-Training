#include <limits.h>
#include <stdio.h>

int main(){
    printf("Header Maximum\n");
    putchar('\n');
    printf("Short minimum: %d\n",SHRT_MIN);
    printf("Short maximum: %d\n",SHRT_MAX);
    printf("Unsigned short maximum: %u\n",USHRT_MAX);
    putchar('\n');
    printf("Integer minimum: %d\n",INT_MIN);
    printf("Integer maximum: %d\n",INT_MAX);
    printf("Unsigned integer maximum: %u\n",UINT_MAX);
    putchar('\n');
    printf("Long minimum: %ld\n",LONG_MIN);
    printf("Long maximum: %ld\n",LONG_MAX);
    printf("Unsigned long maximum: %lu\n",ULONG_MAX);
    putchar('\n');  
    printf("Computed Maximums\n");
    putchar('\n');
    short shorty,shortz;
    shorty = 0;
    shortz = 0;
    while((shorty = shortz - 1) < 0)
        --shortz;
    printf("Short minimum: %d\n",shortz);
    for(shorty=0;shorty > -1;++shorty)
        shortz = shorty;
    printf("Short maximum: %d\n",shortz);
    unsigned short ushorty, ushortz;
    while((ushorty = ushortz + 1) > 0)
        ++ushortz;
    printf("Unsigned short maximum: %u\n",ushortz);
    putchar('\n');
    //Smarter method
    int inty,intz;
    for(inty=0;inty > -1;++inty)
        intz = inty;
    printf("Integer minimum: %d\n",intz*-1-1);
    printf("Integer maximum: %d\n",intz);
    unsigned int uintz;
    uintz = (intz << 1)+1;
    printf("Unsigned integer maximum: %u\n",uintz);
    putchar('\n');
}