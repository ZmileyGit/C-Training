#include <stdio.h>
#include <limits.h>

#define BUFFER_SIZE 50


int ritoa(long num,char buffer[],int b_size);
int ritoa_r(long num,char buffer[],int b_size);
int itoa(long num,char buffer[],int b_size);
void reverse(char str[],int size);
void reverse_r(char str[],int size,int head);

int main(){
    char buffer[BUFFER_SIZE];
    long number = LONG_MIN;
    int size = itoa(number,buffer,BUFFER_SIZE);
    printf("%ld %d %s\n",number,size,buffer);
    size = ritoa(number,buffer,BUFFER_SIZE);
    printf("%ld %d %s\n",number,size,buffer);
    return 0;
}

int ritoa(long num,char buffer[],int b_size){
    b_size -= 2;
    int position = ritoa_r(num,buffer,b_size);
    buffer[position] = '\0';
    return position;
}

int ritoa_r(long num,char buffer[],int b_size){
    short digit = num % 10;
    digit = digit < 0 ? -digit : digit; 
    if((num / 10) == 0){
        short count = 0;
        if(num < 0){
            buffer[count++] = '-';
        }
        buffer[count++] = '0' + digit;
        return count;
    }else{
        int position = ritoa_r((num / 10),buffer,b_size);
        if(position < b_size){
            buffer[position++] = '0' + digit;
        }
        return position;
    }
}

int itoa(long num,char buffer[],int b_size){
    b_size -= 2;
    int count = 0;
    short negative = num < 0 ? 1 : 0;
    do{
        short digit = num % 10;
        if(digit < 0){
            digit = -digit;
        }
        buffer[count++] = '0' + digit;
    }while((num /= 10) != 0 && count < b_size);
    if(negative){
        buffer[count++] = '-';
    }
    buffer[count] = '\0';
    reverse(buffer,count);
    return count;
}

void reverse(char str[],int size){
    reverse_r(str,size,0);
}

void reverse_r(char str[],int size,int head){
    int tail = (size - 1) - head;
    if(head < tail){
        char temp = str[head];
        str[head] = str[tail];
        str[tail] = temp;
        reverse_r(str,size,++head);
    }
}