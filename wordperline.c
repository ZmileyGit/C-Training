#include <stdio.h>

#define IN 1
#define OUT 0
#define START -1

int main(){
    int cursor;
    short status;
    cursor = 0;
    status = START;
    while((cursor = getchar()) != EOF){
        if(cursor == '\r' || cursor == '\n' || cursor == '\t' || cursor == '\b' || cursor == ' '){
            if(status != START){
                status = OUT;
            }
        }else{
            if(status == OUT){
                putchar('\n');
            }
            putchar(cursor);
            status = IN;
        }
    }
    putchar('\n');
    return 0;
}