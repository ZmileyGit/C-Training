#include <stdio.h>

#define LOWER       0
#define UPPER       300
#define STEP        20
#define F_TO_C      (5.0 / 9.0) * (fahrenheit - 32.0)

/* Table Fahrenheit to Celsius */

int main(){
    int fahrenheit;
    float celsius;

    for(fahrenheit=LOWER;fahrenheit<=UPPER;fahrenheit+=STEP){
        celsius = F_TO_C;
        printf("%3d\t%5.1f\n",fahrenheit,celsius);
    }

    printf("----------------------------------\n");

    for(fahrenheit=UPPER;fahrenheit>=LOWER;fahrenheit-=STEP){
        celsius = F_TO_C;
        printf("%3d\t%5.1f\n",fahrenheit,celsius);
    }

    return 0;
}