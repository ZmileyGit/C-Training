#include <stdio.h>

int main(){
    long counter = 0;
    
    //While Form
    while(getchar() != EOF){
        ++counter;
    }
    printf("%ld Characters\n",counter);
}