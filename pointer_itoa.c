#include <stdio.h>

#define BUFFER_SIZE 10

char *itoa(int num,char *buffer);
char *curried_itoa(int num,char *buffer);

int main(){
    char buffer[BUFFER_SIZE]="01256789";
    printf("%s\n",itoa(-5267,buffer));
}

char *itoa(int num,char *buffer){
    char *init = buffer;
    if(num < 0)
        *buffer++ = '-';
    *curried_itoa(num,buffer) = '\0';
    return init;
}

char *curried_itoa(int num,char *buffer){
    int digit = num % 10;
    digit = digit < 0 ? digit * -1 : digit;
    num /= 10;
    if(num != 0){
        buffer = curried_itoa(num,buffer);
    }
    *buffer++ = '0' + digit;
    return buffer;
}