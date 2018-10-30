#include <stdio.h>

#define BUFFER_SIZE 1000

int control_to_escaped(char str[],long length);
int escape_to_control(char str[],long length);
void stdin_to_buffer(char buffer[],long limit);

int main(){
    char buffer[BUFFER_SIZE + 1];
    stdin_to_buffer(buffer,BUFFER_SIZE);
    printf("%s\n",buffer);
}

void stdin_to_buffer(char buffer[], long limit){
    long count;
    int cursor;
    for(count = 0; (cursor = getchar()) != EOF; ++count){
        if(count < limit){
            buffer[count] = cursor;
        }
    }
    buffer[(count < limit ? count : limit)] = '\0';
}