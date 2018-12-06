#include <stdio.h>
#define MEMORY_SIZE 10

static char allocbuff[MEMORY_SIZE];
static char* allocp = allocbuff;

char *nalloc(int size){
    if(allocp - allocbuff + size <= MEMORY_SIZE){
        allocp += size;
        return allocp - size;
    }
    return 0;
}

void nfree(char *pointer){
    if(pointer >= allocbuff && pointer < (allocbuff + MEMORY_SIZE)){
        allocp = pointer;
    }
}

void nprint(void){
    printf("Memory Utilization: %d\n",(allocp - allocbuff));
    for(char *pointer = allocbuff;pointer < (allocbuff + MEMORY_SIZE);++pointer)
        printf("%d -> '%c'\n",pointer,*pointer);
}