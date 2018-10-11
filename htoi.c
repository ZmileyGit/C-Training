#include <stdio.h>
#include <ctype.h>

long naive_htol(char str[]);
long str_len(char str[]);
short hex_to_short_digit(char digit);

int main(){
    printf("%ld\n",naive_htol("234DE"));
    printf("%ld\n",naive_htol("0x59FED"));
    printf("%ld\n",naive_htol("0X32ABCDEF"));
    printf("%ld\n",naive_htol("0x"));
}

long naive_htol(char str[]){
    long num = 0;
    
    long count;
    if(str_len(str) > 2 && str[0] == '0' && tolower(str[1]) == 'x'){
        count = 2;
    }else{
        count = 0;
    }
    for(;isdigit(str[count]) || (tolower(str[count]) >= 'a' && tolower(str[count]) <= 'f');++count){
        num = num * 16 + hex_to_short_digit(str[count]);
    }
    return num;
}

long str_len(char str[]){
    long length;
    for(length = 0;str[length] != '\0';++length);
    return length;
}

short hex_to_short_digit(char digit){
    if(isdigit(digit)){
        return digit - '0';
    }else if((digit = tolower(digit)) >= 'a' && digit <= 'f'){
        return digit - 'a' + 10;
    }
    return 0;
}