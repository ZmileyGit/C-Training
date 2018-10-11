#include <stdio.h>

#define BUFFER_SIZE 100

void squeeze(char str1[],char str2[]);
int any(char str1[],char str2[]);
void cons_to_dynamic_str(char cons[],char buffer[],int buffer_size);

int main(){
    char buffer_1[BUFFER_SIZE];
    cons_to_dynamic_str(
        "Probandotextoestatico",
        buffer_1,
        BUFFER_SIZE
    );
    char buffer_2[BUFFER_SIZE];
    cons_to_dynamic_str(
        "quequequenda",
        buffer_2,
        BUFFER_SIZE
    );
    printf("%d\n",any(buffer_1,buffer_2));
    squeeze(buffer_1,buffer_2);
    printf("%s\n",buffer_1);
}

void squeeze(char str1[],char str2[]){
    long index, dount = 0;
    for(long count = 0;str1[count] != '\0';++count){
        index = -1;
        for(long eount = 0;str2[eount] != '\0' && index == -1;++eount){
            if(str1[count] == str2[eount]){
                index = count;
            }
        }
        if(index == -1){
            str1[dount++] = str1[count];
        }
    }
    str1[dount] = '\0';
}

int any(char str1[],char str2[]){
    long index = -1;
    for(long count = 0;str1[count] != '\0' && index == -1;++count){
        for(long eount = 0;str2[eount] != '\0' && index == -1;++eount){
            if(str1[count] == str2[eount]){
                index = count;
            }
        }
    }
    return index;
}

void cons_to_dynamic_str(char cons[],char buffer[],int buffer_size){
    long count;
    for(count = 0;cons[count] != '\0' && count < (buffer_size - 1);++count){
        buffer[count] = cons[count];
    }
    buffer[count] = '\0';
}