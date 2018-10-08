#include <stdio.h>

#define MAX_LENGTH 15
#define BAR '#'
#define EMPTY ' '

int main(){
    int cursor = 0;

    long lengths[MAX_LENGTH];
    for(int count=0;count < MAX_LENGTH;++count)
        lengths[count] = 0;
    long word_length = 0;

    while((cursor = getchar()) != EOF){
        if(cursor == ' ' || cursor == '\t' || cursor == '\n'){
            if(word_length > 0){
                --word_length;
                if(word_length >= MAX_LENGTH){
                    word_length = MAX_LENGTH-1;
                }
                ++lengths[word_length];
            }
            word_length = 0;
        }else{
            ++word_length;
        }
    }

    long max_repeat = 0;
    for(int count = 0;count < MAX_LENGTH;++count){
        if(lengths[count] > max_repeat){
            max_repeat = lengths[count];
        }
    }

    for(int count = max_repeat;count > 0;--count){
        for(int coun = 0;coun < MAX_LENGTH;++coun){
            printf("  ");
            if(lengths[coun] >= count){
                putchar(BAR);
            }else{
                putchar(EMPTY);
            }
            printf("  ");
        }
        putchar('\n');
    }

    for(int count = 0;count < MAX_LENGTH; ++count){
        if(count != (MAX_LENGTH-1)){
            printf(" %3d ",count+1);
        }else{
            printf(" %3d>",count+1);   
        }
    }
    putchar('\n');
}