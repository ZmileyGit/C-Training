#include <stdio.h>

#define MAX_LINES 1000
#define WORD_SIZE 100

int getLine(char *buffer, int size);
int getLines(char *lines[], int size, int word_size,char *memory);
void printLines(char *lines[], int size);
int n_strcmp(char *s1,char *s2, int length);
void qsort(char *lines[], int left, int right);
void swap(char *lines[], int left, int right);

int main(){
    char memory[MAX_LINES * WORD_SIZE];
    char *lines[MAX_LINES];
    int line_number = getLines(lines,MAX_LINES,WORD_SIZE,memory);
    qsort(lines,0,line_number - 1);
    printLines(lines,line_number);
    return 0;
}

// Line processing

int getLine(char *buffer, int size){
    char *init = buffer;
    int cursor;
    while((cursor = getchar()) != EOF && cursor != '\n'){
        if(buffer < (init + size - 1)){
            *buffer++ = cursor;
        }
    }
    *buffer = '\0';
    buffer += (cursor == '\n') ? 1 : 0;
    return buffer - init;
}

int getLines(char *lines[],int size,int word_size,char *memory){
    int memory_size = size * word_size;
    char *memory_init = memory;
    int count;
    int word_len;
    for(count = 0;count < size && (word_len = getLine(memory,word_size));++count,memory+=word_len){
        *lines++ = memory; 
    }
    return count;
}

void printLines(char *lines[],int size){
    for(int count = 0;count < size;++count){
        printf("%ld   %s\n",count,*lines++);
    }
}

//String operations

int n_strcmp(char *s1,char *s2,int length){
    for(;length && *s1 && *s2;--length,s1++,s2++){
        if(*s1 != *s2){
            return *s1 - *s2;
        }
    }
    if(length){
        return *s1 - *s2;
    }
    return 0;
}

// Sorting

void qsort(char *lines[],int left,int right){
    if(right > left){
        int pivot = (right + left) / 2;
        int lount,rount;
        lount = left;
        rount = right;
        while(rount > lount){
            if(n_strcmp(*(lines + lount),*(lines + pivot),WORD_SIZE) > 0){
                swap(lines,lount,rount);
                if(rount == pivot){
                    pivot = lount;
                }
                rount--;
            }else if(lount == pivot){
                swap(lines,pivot,pivot + 1);
                pivot++;
            }else{
                lount++;
            }
        }
        qsort(lines,left,pivot - 1);
        qsort(lines,pivot + 1,right);
    }
}

void swap(char *lines[],int left,int right){
    char *temp = *(lines + left);
    *(lines + left) = *(lines + right);
    *(lines + right) = temp;
}