#include <stdio.h>

#define MAX_BUFFER 1000
#define START 0
#define INLINE 1

long get_trimmed_line(char buffer[],int buffer_size);

int main(){
    char buffer[MAX_BUFFER];
    long length;
    while((length=get_trimmed_line(buffer,MAX_BUFFER)) >= 0){
        if(length > 0){
            printf("%s\n",buffer,length);
        }
    }
}

long get_trimmed_line(char buffer[],int buffer_size){
    int cursor, status;
    long position;
    status = START;
    position = -1;
    while((cursor=getchar()) != EOF && cursor != '\n'){
        if(status == START && cursor != ' ' && cursor != '\t'){
            status = INLINE;
            position = 0;
        }
        if(status == INLINE && position < buffer_size){
            buffer[position] = cursor;
            ++position;
        }
    }
    if(position == buffer_size){
        buffer[buffer_size-1] = '\0';
    }else{
        buffer[position] = '\0';
    }
    if(cursor == '\n'){
        ++position;
    }
    return position;
}