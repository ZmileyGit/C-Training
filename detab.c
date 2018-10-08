#include <stdio.h>

#define TAB_SIZE 4

int main(){
    int cursor;
    while((cursor=getchar()) != EOF){
        if(cursor == '\t'){
            for(int count = 0;count < TAB_SIZE;++count){
                putchar(' ');
            }
        }else{
            putchar(cursor);
        }
    }
    return 0;
}