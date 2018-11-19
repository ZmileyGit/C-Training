#include <stdio.h>

#define BUFFER_SIZE 100
#define SEARCH "ould"

int getbufferedline(char buffer[],int buffer_size);
int strbufferlen(char str[]);
int strindex(char str[],char substr[]);
int strlastindex(char str[],char substr[]);

int main(){
    char buffer[BUFFER_SIZE];
    while(getbufferedline(buffer,BUFFER_SIZE) > 0){
       printf("%5d | %5d # %s\n",strindex(buffer,SEARCH),strlastindex(buffer,SEARCH),buffer);
    }
    return 0;
}

int strindex(char str[],char substr[]){
    int str_len = strbufferlen(str);
    int substr_len = strbufferlen(substr);
    int count = 0, dount = 0;
    for(count = 0;count < str_len && dount < substr_len;++count){
        dount = str[count] == substr[dount] ? dount + 1 : 0;
    }
    return dount == substr_len ? count - dount : -1;
}

int strlastindex(char str[],char substr[]){
    int str_len = strbufferlen(str);
    int substr_len = strbufferlen(substr);
    int count = 0, dount = 0;
    for(count = (str_len - 1);count >= 0 && dount < substr_len;--count){
        dount = str[count] == substr[(substr_len - 1) - dount] ? dount + 1 : 0;
    }
    return dount == substr_len ? count + 1 : -1;
}

int strbufferlen(char str[]){
    int count;
    for(count = 0;str[count] != '\0';++count);
    return count;
}

int getbufferedline(char buffer[],int buffer_size){
    --buffer_size;
    int len = 0, cursor;
    while((cursor = getchar()) != EOF && cursor != '\n'){
        if(len < buffer_size){
            buffer[len++] = cursor;
        }
    }
    buffer[len] = '\0';
    len += cursor == '\n' ? 1 : 0;
    return len;
}