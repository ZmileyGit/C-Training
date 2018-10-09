#include <stdio.h>

#define NORMAL 0
#define SLASH_FOUND 1
#define IN_MLTLINE 2
#define IN_SNGLINE 3

#define IN_MLTLINE_CLOSE_PENDING 4

int main(){
    int cursor, status;
    status = NORMAL;

    while((cursor = getchar()) != EOF){
        if(status == SLASH_FOUND){
            if(cursor == '*'){
                status = IN_MLTLINE;
            }else if(cursor == '/'){
                status = IN_SNGLINE;
            }else{
                status = NORMAL;
                putchar('/');
                putchar(cursor);
            }
        }else if(status == IN_MLTLINE){
            if(cursor == '*'){
                status = IN_MLTLINE_CLOSE_PENDING;
            }
        }else if(status == IN_MLTLINE_CLOSE_PENDING){
            if(cursor == '/'){
                status = NORMAL;
            }else{
                status = IN_MLTLINE;
            }
        }else if(status == IN_SNGLINE){
            if(cursor == '\n'){
                status = NORMAL;
            }else{
                status = IN_SNGLINE;
            }
        }else if(cursor == '/'){
            status = SLASH_FOUND;
        }else if(status == NORMAL){
            putchar(cursor);
        }
    }
}