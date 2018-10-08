#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP  20

double fahrenheit_to_celsius(double f);
double celsius_to_fahrenheit(double c);

int main(){
    printf("F to C\n");
    for(int count=LOWER;count<=UPPER;count+=STEP){
        printf("%5d F -> %5.1f C\n",count,fahrenheit_to_celsius(count));
    }
    printf("C to F\n");
    for(int count=LOWER;count<=UPPER;count+=STEP){
        printf("%5d C -> %5.1f F\n",count,celsius_to_fahrenheit(count));
    }
    return 0;
}

double fahrenheit_to_celsius(double f){
    return (5.0 / 9.0) * (f - 32.0);
}

double celsius_to_fahrenheit(double c){
    return (1.0 / 5.0)*(8.0 * (c + 20.0) + c);
}
