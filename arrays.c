#include <stdio.h>

int main(){
    long digits[10];
    long blanks,others;

    blanks = others = 0;
    for(int count = 0;count < 10; ++count)
        digits[count] = 0;

    int cursor;
    cursor = 0;
    while((cursor = getchar()) != EOF){
        if(cursor >= '0' && cursor <= '9'){
            ++digits[cursor-'0'];
        }else if(cursor == ' ' || cursor == '\t' || cursor == '\n'){
            ++blanks;
        }else{
            ++others;
        }
    }

    printf("Digits\n");
    for(int count = 0;count < 10;++count){
        printf("%d: %d\n",count,digits[count]);
    }
    printf("Blanks\n");
    printf("%d\n",blanks);
    printf("Others\n");
    printf("%d\n",others);
}