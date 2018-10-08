#include <stdio.h>

// Copy input to output

int main(){
    int my_char;
    while((my_char=getchar()) != EOF){
        printf("%d: ",(my_char != EOF));
        putchar(my_char);
        printf("\n");
    }
    printf("%d: ",(my_char != EOF));
    printf("%d\n",my_char);
    printf("The value of EOF is %d\n",EOF);
}