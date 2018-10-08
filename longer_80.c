#include <stdio.h>

#define MAX_BUFFER 200
#define UPPER_CAP 80

long get_line(char buffer[],int max_size);

int main(){
    char buffer[MAX_BUFFER];
    long length;
    while((length=get_line(buffer,MAX_BUFFER)) > 0){
        if(length > UPPER_CAP){
            printf("-%s\t[%ld]\n",buffer,length);
        }
    }
}

long get_line(char buffer[],int buffer_size){
    int cursor;
    long length;
    length = 0;  
    while((cursor=getchar()) != EOF && cursor != '\n'){
        if(length < buffer_size){
            buffer[length] = cursor;
        }
        ++length;
    }
    if(length >= buffer_size){
        buffer[buffer_size-1] = '\0';
    }else{
        buffer[length] = '\0';
    }
    if(cursor == '\n'){
        ++length;
    }
    return length;
}