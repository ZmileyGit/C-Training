#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[],int maxline);
void copy(char to[], char from[]);

int main(){
    int length,position;
    int max[2];
    char line[MAXLINE];
    char longest[MAXLINE];
    for(int count=0;count<MAXLINE;++count){
        longest[count] = '\0';
    }

    max[0] = 0;
    max[1] = 0;
    position = 0;

    while((length=get_line(line,MAXLINE))>0){
        ++position;
        //printf("%s\n",line);
        if(length > max[0]){
            max[0] = length;
            max[1] = position;
            copy(longest,line);
        }
    }

    if(max > 0 && line > 0){
        printf("Longest line found at line %d with %d characters\n",max[1],max[0]);
        printf("-%s\n",longest);
    }

    return 0;
}

int get_line(char line[],int maxline){
    int length,cursor;
    length = 0;
    while((cursor=getchar()) != EOF && cursor != '\n'){
        if(length < maxline){
            line[length] = cursor;
        }
        ++length;
    }
    if(length >= maxline){
        line[maxline-1]='\0';
    }else{
        line[length]='\0';
    }
    if(cursor == '\n'){
        ++length;
    }
    return length;
}

void copy(char to[],char from[]){
    for(int count=0;from[count] != '\0';++count){
        to[count] = from[count];
    }
}