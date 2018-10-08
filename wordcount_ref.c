#include <stdio.h>

#define IN 1
#define OUT 0

int main(){
    int cursor;
    short status;

    long words, lines, chars;
    words = 0;
    lines = 0;
    chars = 0;

    while((cursor = getchar()) != EOF){
        if(cursor == '\n'){
            ++lines;
        }
        if(cursor == '\n' || cursor == ' ' || cursor == '\t'){
            status = OUT;
        }else if(status == OUT){
            status = IN;
            ++words;
        }
        ++chars;
    }

    printf("Words: %ld Lines: %ld Chars: %ld\n",words,lines,chars);

    return 0;
}