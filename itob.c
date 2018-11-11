#include <stdio.h>
#include <limits.h>

#define BUFFER_SIZE 100
#define TO_BASE 2

int itob(int from,char to[],int str_len,short base);
char dtoc(short digit);
void reverse(char str[], int length);

int main(){
    char buffer[BUFFER_SIZE];
    int num = INT_MIN;
    itob(num,buffer,BUFFER_SIZE,TO_BASE);
    printf("%s\n",buffer);

    num = INT_MAX;
    itob(num,buffer,BUFFER_SIZE,TO_BASE);
    printf("%s\n",buffer);

    itob(0,buffer,BUFFER_SIZE,TO_BASE);
    printf("%s\n",buffer);

    return 0;
}

int itob(int from, char to[], int str_len,short base){
    str_len -= 2;
    short sign = from < 0 ? 1 : 0;
    int count = 0;
    do{
        int digit = from % base;
        if(digit < 0)
            digit = -digit;
        to[count++] = dtoc(digit); 
    }while((from /= base) != 0 && count < str_len);
    if(sign)
        to[count++] = '-';
    to[count] = '\0';
    reverse(to,count);
    return count;
}

char dtoc(short digit){
    if(digit >= 0 && digit <= 9){
        return '0' + digit;
    }else if(digit >= 10 && digit <= 15){
        return 'A' + (digit % 10);
    }else{
        return '?';
    }
}

void reverse(char str[], int length){
    char temp = 0;
    for(int left = 0, right = (length - 1);left < right;++left,--right){
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
    }
}