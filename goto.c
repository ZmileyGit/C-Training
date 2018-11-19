#include <stdio.h>

int main(){
    for(int count = 0;count < 100; ++count){
        printf("%d\n",count);
        if(count > 20){
            goto jump;
        }
    }
    jump:{
        printf("You jumped,\n");
        printf("and ran multiple lines\n");
    }
}