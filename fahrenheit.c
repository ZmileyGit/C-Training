#include <stdio.h>

/*
Print Fahrenheit-Celsius Table
*/

int main(){
    int fahr, celsius;
    float fcelsius;
    int lower = 0, upper = 300, step = 20;

    fahr = lower;
    printf("[\tInteger Arithmetic\t]\n");
    printf("| Fahrenheit |  Celsius  |\n");
    while(fahr <= upper){
        celsius = (5 * (fahr - 32)) / 9;
        printf("|   %6d   |   %5d   |\n",fahr,celsius);
        fahr += step;
    }

    fahr = upper;
    printf("\n[\tFloating Point Arithmetic\t]\n");
    printf("| Fahrenheit |  Celsius  |\n");
    while(fahr >= lower){
        fcelsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("|   %6.0f   |   %5.1f   |\n",(float)fahr,fcelsius);
        fahr -= step;
    }

    float fahrenheit;
    celsius = lower;
    printf("\n|  Celsius  | Fahrenheit |\n");
    while(celsius <= upper){
        fahrenheit = (1.0/5.0)*(8.0*(celsius+20.0)+celsius);
        printf("|   %5.0f   |   %6.1f   |\n",(float)celsius,fahrenheit);
        celsius += step;
    }

    printf("\n[\tInteger to Floating Point\t]\n");
    float my_num = 1 - 0.2;
    printf("%f\n",my_num);

    return 0;
}