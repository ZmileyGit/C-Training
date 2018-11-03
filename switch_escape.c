#include <stdio.h>

#define BUFFER_SIZE 1000
#define DEFAULT     0
#define NEW_LINE    1
#define TAB         2

#define ESCAPE      100

long control_to_escape(char str[],long length);
long escape_to_control(char str[],long length);
long stdin_to_buffer(char buffer[],long limit);
void copy_buffer(char src[],char dst[],long length);

int main(){
    char buffer[BUFFER_SIZE];
    long size = stdin_to_buffer(buffer,BUFFER_SIZE);
    printf("---Original[%ld]---\n%s\n",size,buffer);
    size = control_to_escape(buffer,size);
    printf("---Control to Escape[%ld]---\n%s\n",size,buffer);
    size = escape_to_control(buffer,size);
    printf("---Escape to Control[%ld]---\n%s\n",size,buffer);
}

long stdin_to_buffer(char buffer[], long limit){
    long count;
    int cursor;
    for(count = 0; (cursor = getchar()) != EOF; ++count){
        if(count < limit){
            buffer[count] = cursor;
        }
    }
    long size = count < limit ? count : limit;
    buffer[size - 1] = '\0';
    return size;
}

long escape_to_control(char str[],long length){
    char carbon[BUFFER_SIZE];
    short status = DEFAULT;
    copy_buffer(str,carbon,length);
    long count, dount;
    for(count = 0, dount = 0; carbon[count] != '\0'; ++count){
        switch(status){
            case DEFAULT:
                switch(carbon[count]){
                    case '\\':
                        status = ESCAPE;
                    break;
                    default:
                        str[dount++] = carbon[count];
                    break;
                }
            break;
            case ESCAPE:
                switch(carbon[count]){
                    case 'n':
                        str[dount++] = '\n';
                    break;
                    case 't':
                        str[dount++] = '\t';
                    break;
                    default:
                        str[dount++] = '\\';
                        count--;
                    break;
                }
                status = DEFAULT;
            break;
        }
    }
    str[dount] = '\0';
    return ++dount;
}

long control_to_escape(char str[],long length){
    char carbon[BUFFER_SIZE];
    copy_buffer(str,carbon,length);
    short status = DEFAULT;
    long count, dount;
    for(count = 0, dount = 0; (carbon[dount] != '\0' && count < (BUFFER_SIZE - 1)) || (status != DEFAULT && count < (BUFFER_SIZE - 2)); ++count){
        switch(status){
            case DEFAULT:
                switch(carbon[dount]){
                    case '\n':
                        str[count] = '\\';
                        status = NEW_LINE;
                    break;
                    case '\t':
                        str[count] = '\\';
                        status = TAB;
                    break;
                    default:
                        str[count] = carbon[dount];
                    break;
                }
                ++dount;
            break;
            case NEW_LINE:
                str[count] = 'n';
                status = DEFAULT;
            break;
            case TAB:
                str[count] = 't';
                status = DEFAULT;
            break;
        }
    }
    str[count] = '\0';
    return ++count;
}

void copy_buffer(char src[], char dst[], long length){
    for(long count = 0; count < length; ++count){
        dst[count] = src[count];
    }
}