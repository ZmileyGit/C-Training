#include <stdio.h>

#define BUFFER_SIZE 100

long get_line(char line[],long size);

int main(){
    char line[BUFFER_SIZE + 1];
    line[BUFFER_SIZE] = '\n';
    long length;
    while((length = get_line(line,BUFFER_SIZE)) > 0){
        printf("%s\n",line);    
    }
}

long get_line(char line[],long size){
    int cursor;
    long count;
    for(count = 0L;(count < size) * ((cursor = getchar()) != '\n') * (cursor != EOF);++count){
        line[count] = cursor;
    }
    line[count] = '\0';
    if(cursor == '\n'){
        ++count;
    }
    return count;
}