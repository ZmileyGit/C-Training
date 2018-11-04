#include <stdio.h>

#define LENGTH 10000

void shell_sort(int vector[],unsigned int length);
void print_vector(int vector[],unsigned int length);
void swap_columns(int vector[],unsigned int src,unsigned int dst);

int main(){
    int vector[LENGTH];
    for(unsigned int count = 0;count < LENGTH;++count){
        vector[count] = (LENGTH-1) - count;
    }
    shell_sort(vector,LENGTH);
    print_vector(vector,LENGTH);
    return 0;
}

void print_vector(int vector[],unsigned int length){
    putchar('[');
    for(unsigned int count = 0;count < length;++count){
        printf("%d%s",vector[count],count < (length -1) ? "," : "");
    }
    putchar(']');
    putchar('\n');
}

void shell_sort(int vector[],unsigned int length){
    for(unsigned int gap = length >> 1; gap > 0;gap >>= 1){
        for(long count = gap; count < length; ++count){
            for(long dount = count - gap; dount >= 0 && vector[dount] > vector[dount + gap];dount -= gap){
                swap_columns(vector,dount,dount + gap);
            }
        }
    }
}

void swap_columns(int vector[],unsigned int src, unsigned int dst){
    int transition = vector[dst];
    vector[dst] = vector[src];
    vector[src] = transition;
}