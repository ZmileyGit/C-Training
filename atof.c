#include <stdio.h>
#include <ctype.h>

#define BUFFER_SIZE 100

int getbufferedline(char buffer[],int size);
double atof(char str[]);

int main(){
    char buffer[BUFFER_SIZE];
    int length;
    while((length = getbufferedline(buffer,BUFFER_SIZE)) >= 0){
        printf("%g\n",atof(buffer));
    }
    return 0;
}

double atof(char str[]){

    double result = 0.0;
    int position = 0;
    short sign;

    for(;isspace(str[position]);++position);

    sign = str[position] == '-' ? -1 : 1; 
    if(str[position] == '-' || str[position] == '+'){
        position++;
    }

    for(;isdigit(str[position]);++position){
        result = (10.0 * result) + (str[position] - '0');
    }

    if(str[position] == '.'){
        position++;
        int fractional = 0;
        double power = 1.0;
        for(;isdigit(str[position]);++position){
            fractional = (10 * fractional) + (str[position] - '0');
            power *= 10.0;
        }
        result += (fractional / power);
    }

    if(str[position] == 'E' || str[position] == 'e'){
        position++;
        int exponent = 0;
        short exp_neg = str[position] == '-' ? 1 : 0;
        if(str[position] == '-' || str[position] == '+'){
            position++;
        }
        for(;isdigit(str[position]);position++){
            exponent = (10 * exponent) + (str[position] - '0'); 
        }
        double power = 1.0;
        for(int count = 0;count < exponent;++count){
            power *= 10.0;
        }
        if(exp_neg){
            result /= power;
        }else{
            result *= power;
        }
    }

    return sign * result;
}

int getbufferedline(char buffer[],int size){
    --size;
    int cursor, length;
    length = -1;
    while((cursor = getchar()) != EOF && cursor != '\n'){
        if((length + 1) < size){
            buffer[++length] = cursor;
        }
    }
    if(cursor == '\n' || (length + 1) > 0){
        buffer[++length] = '\0';
    }
    return length;
}