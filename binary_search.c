#include <stdio.h>

#define SIZE 1000000

int book(int needle,int haystack[],int length);
int challenge(int needle,int haystack[],int length);

int main(){
    int haystack[SIZE];
    for(int count = 0;count < SIZE;++count){
        haystack[count] = count;
    }
    printf("%d\n",challenge(700,haystack,SIZE));
    return 0;
}

int book(int needle,int haystack[],int length){
    int low, high, middle;

    low = 0;
    high = length - 1;

    while(low <= high){
        middle = low + (high - low) / 2;
        if(haystack[middle] < needle){
            low = middle + 1;
        }else if(haystack[middle] > needle){
            high = middle - 1;
        }else{
            return middle; 
        }
    }

    return -1;
}

int challenge(int needle, int haystack[], int length){
    int low, high, middle;

    low = 0;
    high = length - 1;

    while(haystack[(middle = low + (high - low)/2)] != needle && low < high){
        if(needle > haystack[middle]){
            low = middle + 1;
        }else{
            high = middle - 1;
        }
    }

    return haystack[middle] == needle ? middle : -1;
}