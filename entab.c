#include <stdio.h>

#define TAB_SIZE 4
#define OUT 0
#define IN 1

int main(){
    short state;
    int cursor;
    long blanks;

    blanks = 0;
    state = OUT;

    while((cursor = getchar()) != EOF){
        if(state == OUT && cursor == ' '){
            state = IN;
            ++blanks;
        } else if(state == IN && cursor == ' '){
            ++blanks;
        }else{
            if(blanks > 0){
                long tabs = blanks / TAB_SIZE;
                for(long count = 0;count < tabs;++count){
                    putchar('\t');
                }
                blanks = blanks % TAB_SIZE;
                for(long count = 0;count < blanks;++count){
                    putchar(' ');
                }
            }
            putchar(cursor);
            blanks = 0;
            state = OUT;
        }
    }
}