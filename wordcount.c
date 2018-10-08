#include <stdio.h>

#define WORD cursor != '\n' && cursor != '\t' && cursor != ' '

int main(){
    int cursor;

    long words, lines, chars;
    words = 0;
    lines = 0;
    chars = 0;
    cursor = getchar();
    while(cursor != EOF){
        if(cursor == '\n'){
            ++lines;
        }
        if(WORD){
            ++words;
            while((cursor=getchar()) != EOF && WORD){
                ++chars;
            }
        }else{
            ++chars;
            cursor = getchar();
        }
    }

    printf("Words: %ld Lines: %ld Chars: %ld\n",words,lines,chars);

    return 0;
}