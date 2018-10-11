#include <stdio.h>

int naive_atoi(char str[]);
char naive_lower(char charsy);

int main(){
    printf("%d\n",naive_atoi("970"));
    printf("%c\n",naive_lower('E'));
}

int naive_atoi(char str[]){
    int num = 0;
    for(int count = 0;str[count] >= '0' && str[count] <= '9';++count){
        num = 10 * num + (str[count] - '0');
    }
    return num;
}

char naive_lower(char charsy){
    if(charsy >= 'A' && charsy <= 'Z'){
        return charsy - 'A' + 'a';
    }else{
        return charsy;
    }
}