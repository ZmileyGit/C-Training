#include <stdio.h>
#include <limits.h>

#define BUFFER_SIZE 100

int naive(int num,char str[],int str_len);
int itoa(int num,char str[],int str_len);
void pitoa(int num,char str[],int str_len,int width);
void reverse(char str[], int length);

int main(){

    char buffer[BUFFER_SIZE];
    int num = INT_MIN;
    itoa(num,buffer,BUFFER_SIZE);
    printf("%s\n",buffer);

    num = INT_MAX;
    itoa(num,buffer,BUFFER_SIZE);
    printf("%s\n",buffer);

    itoa(0,buffer,BUFFER_SIZE);
    printf("%s\n",buffer);

    pitoa(INT_MIN,buffer,BUFFER_SIZE,20);
    printf("%s\n",buffer);

    return 0;
}

void pitoa(int num,char str[],int str_len,int min_len){
    int length = itoa(num,str,str_len);
    --str_len;
    if(length < min_len){
        int padding = length + (min_len - length);
        padding = padding > str_len ? str_len : padding;
        padding -= length;
        for(int count = length;count >= 0;--count){
            if((count + padding) < str_len){
                str[count + padding] = str[count];
            }
        }
        for(int count = 0;count < padding;++count){
            str[count] = ' ';
        }
        str[str_len] = '\0';
    }
}

int itoa(int num,char str[],int str_len){
    str_len -= 2;
    int count = 0;
    short sign = num < 0 ? 1 : 0;
    do{
        int digit = num % 10;
        if(digit < 0)
            digit = -digit;
        str[count++] = '0' + digit;
    }while((num /= 10) != 0);
    if(sign)
        str[count++] = '-';
    str[count] = '\0';
    reverse(str,count);
    return count;
}

int naive(int num,char str[],int str_len){
    int sign, count;
    if((sign = num) < 0){
        num = -num;
        --str_len;
    }
    count = 0;
    --str_len;
    do{
        str[count++] = (num % 10) + '0'; 
    }while((num /= 10) > 0 && count < str_len);
    if(sign < 0){
        str[count++] = '-';
    }
    str[count] = '\0';
    reverse(str,count);
    return count;
}

void reverse(char str[], int length){
    char temp = 0;
    for(int left = 0, right = (length - 1);left < right;++left,--right){
        temp = str[left];
        str[left] = str[right];
        str[right] = temp;
    }
}