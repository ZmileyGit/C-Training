#include <stdio.h>
#define SIZE 38
#define COLUMNS 10

void print_x_by_x(int array[],int length,int x);

int main(){
    int nums[SIZE];
    for(int count = 0; count < SIZE ; count++){
        nums[count] = count;
    }
    print_x_by_x(nums,SIZE,COLUMNS);

    int cursor;
    while((cursor = getchar()) != EOF){
        printf("%c",(cursor >= 'A' && cursor <= 'Z')?(cursor - 'A' + 'a'):cursor);
    }
    return 0;
}

void print_x_by_x(int array[],int length,int x){
    for(int count = 0;count < length;count++){
        printf("%5d%c",array[count],(count % x == (x - 1) || count == (length - 1))? '\n' : ' ');
    }
}