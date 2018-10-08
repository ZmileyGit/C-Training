#include <stdio.h>

int main(){
    double counter;

    for(counter=0;getchar() != EOF;++counter);

    printf("%.0f Characters\n",counter);
}