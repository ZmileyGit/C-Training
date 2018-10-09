#include <stdio.h>

#define NORMAL          0
#define IN_STRING       1
#define ESCAPING_S      2
#define IN_CHAR         3
#define ESCAPING_C      4
#define PRE_COMMENT     5
#define IN_COMMENT      6
#define COMMENT_CLOSING 7

#define TRUE 1
#define FALSE 0
int main(){
    int cursor;
    int status;
    short bracket_error = FALSE;
    short string_error = FALSE;
    short parentheses_error = FALSE;
    short char_error = FALSE; 
    long parentheses = 0;
    long quotes = 0;
    long ticks = 0;
    long brackets = 0;
    long lines = 0;
    long column = 0;
    while((cursor = getchar()) != EOF){
        if(status == NORMAL){
            if(cursor == '('){
                ++parentheses;
            }else if(cursor == ')'){
                --parentheses;
                if(parentheses < 0){
                    parentheses_error = TRUE;
                    printf("Closing parentheses before opening one at Line %d, Column %d\n",lines+1,column+1);
                }
            }else if(cursor == '"'){
                status = IN_STRING;
                ++quotes;
            }else if(cursor == '\''){
                status = IN_CHAR;
                ++ticks;
            }else if(cursor == '{'){
                ++brackets;
            }else if(cursor == '}'){
                --brackets;
                if(brackets < 0){
                    bracket_error = TRUE;
                    printf("Closing bracket before opening one at Line %d, Column %d\n",lines+1,column+1);
                }
            }else if(cursor == '/'){
                status = PRE_COMMENT;
            }
        }else if(status == IN_STRING){
            if(cursor == '\\'){
                status = ESCAPING_S;
            }else if(cursor == '"'){
                status = NORMAL;
                --quotes;
            }else if(cursor == '\n'){
                status = NORMAL;
                printf("Unended string at Line %d, Column %d\n",lines+1,column+1);
            }
        }else if(status == IN_CHAR){
            if(cursor == '\\'){
                status = ESCAPING_C;
            }else if(cursor == '\''){
                status = NORMAL;
                --ticks;
            }else if(cursor == '\n'){
                status = NORMAL;
                printf("Unended char at Line %d, Column %d\n",lines+1,column+1);
            }
        }else if(status == ESCAPING_S){
            status = IN_STRING;
        }else if(status == ESCAPING_C){
            status = IN_CHAR;
        }else if(status == PRE_COMMENT){
            if(cursor == '*'){
                status = IN_COMMENT;
            }else{
                status = NORMAL;
            }
        }else if(status == IN_COMMENT){
            if(cursor == '*'){
                status = COMMENT_CLOSING;
            }else{
                status = IN_COMMENT;
            }
        }else if(status == COMMENT_CLOSING){
            if(cursor == '/'){
                status = NORMAL;
            }else{
                status = IN_COMMENT;
            }
        }
        ++column;
        if(cursor == '\n'){
            ++lines;
            column = 0;
        }
    }
    if(parentheses != 0){
        printf("Unbalanced parentheses found.\n");
    }
    if(parentheses != 0){
        printf("Unbalanced brackets found.\n");
    }
    if(quotes != 0){
        printf("Unbalanced double quotes found.\n");
    }
    if(ticks != 0){
        printf("Unbalanced single quotes found.\n");
    }
    if(status == IN_COMMENT || status == COMMENT_CLOSING){
        printf("Reached EOF within a comment.\n");   
    }
    return 0;
}