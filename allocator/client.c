#include "manager.h"
#include <stdio.h>

int main(){
    for(int count = 0;count < 10;++count){
        char * pointer = nalloc(count);
        char * copy = pointer;
        for(int dount = 0; pointer && dount < count; ++dount){
            *(pointer + dount) = 'a' + dount;
            copy++;
        }
        printf("%d %d\n",pointer,copy);
        nprint();
        nfree(pointer);
    }
    return 0;
}