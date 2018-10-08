#include <stdio.h>

#define MAX_BUFFER 1000

long get_line(char buffer[],long buffer_size);
void reverse(char line[],long size);

int main(){
    char buffer[MAX_BUFFER];
    long length,effective_length;
    while((length=get_line(buffer,MAX_BUFFER)) > 0){
        if(length >= MAX_BUFFER){
            effective_length = MAX_BUFFER; 
        }else{
            effective_length = length;
        }
        --effective_length;
        reverse(buffer,effective_length);
        printf("%s\n",buffer);
    }
}

void reverse(char line[], long size){
    long length;
    int left;
    for(int count = 0; count < (size/2);++count){
        left = line[count];
        line[count] = line[(size-1)-count];
        line[(size-1)-count] = left;
    }
}

long get_line(char buffer[],long buffer_size){
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
    if(cursor == '\n' || (length > 0 && cursor == EOF)){
        ++length;
    }
    return length;
}