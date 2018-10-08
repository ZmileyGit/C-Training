#include <stdio.h>

#define MAX_BUFFER 1000

long max;
char buffer[MAX_BUFFER];
char longest[MAX_BUFFER];

long get_line(void);
void copy(void);

int main(){
    long length;
    extern long max;
    extern char longest[];
    while((length = get_line()) > 0){
        if(length > max){
            max = length;
            copy();
        }
    }
    printf("Longest : %ld\n%s\n",max,longest);
    return 0;
}

long get_line(void){
    long length;
    int cursor;
    extern char buffer[];

    length = 0;

    while((cursor=getchar()) != EOF && cursor != '\n'){
        if(length < MAX_BUFFER){
            buffer[length] = cursor;
        }
        ++length;
    }
    if(length >= MAX_BUFFER){
        buffer[MAX_BUFFER-1] = '\0';
    }else{
        buffer[length] = '\0';
    }
    if(cursor == '\n'){
        ++length;
    }
    return length;
}

void copy(void){
    extern char buffer[], longest[];
    for(long count=0;buffer[count] != '\0' && count < MAX_BUFFER;++count){
        longest[count]=buffer[count];
    }
}