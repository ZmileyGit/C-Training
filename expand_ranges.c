#include <stdio.h>

#define BUFFER_SIZE 1000

enum parser_status{
    DEFAULT = 1,
    LOWER_CASE = 2,
    UPPER_CASE = 3,
    NUMBER = 4,
    LOWER_RANGE = 5,
    UPPER_RANGE = 6,
    NUMBER_RANGE
};

long stdin_to_buffer(char buffer[]);
void expand_ranges(char src[],long src_len,char dst[],long dst_len);

int main(){
    char buffer[BUFFER_SIZE];
    char expanded[BUFFER_SIZE];
    long buff_len = stdin_to_buffer(buffer);
    printf("------\n%s\n",buffer);
    expand_ranges(buffer,buff_len,expanded,BUFFER_SIZE);
    printf("------\n%s\n",expanded);
}

long stdin_to_buffer(char buffer[]){
    long length = 0;
    int cursor;
    while((cursor = getchar()) != EOF && length < (BUFFER_SIZE - 1)){
        buffer[length++] = cursor;
    }
    buffer[length] = '\0';
}

void expand_ranges(char src[],long src_len,char dst[],long dst_len){
    short status = DEFAULT;
    int dount = 0;
    char queue = '\0';
    --dst_len;
    for(int count = 0;count < src_len && dount < dst_len;++count){
        if(status == DEFAULT){
            if(queue != '\0'){
                dst[dount++] = queue;
                count--;
                queue = '\0';
            }else if(src[count] >= 'a' && src[count] <= 'z'){
                status = LOWER_CASE;
                queue = src[count];
            }else if( src[count] >= 'A' && src[count] <= 'Z'){
                status = UPPER_CASE;
                queue =  src[count];
            }else if(src[count] >= '0' && src[count] <= '9'){
                status = NUMBER;
                queue = src[count];
            }else{
                dst[dount++] = src[count];
            }
        }else if(status == LOWER_CASE){
            if(src[count] == '-'){
                status = LOWER_RANGE;
            }else{
                dst[dount++] = queue;
                queue = src[count];
                status = DEFAULT;
            }
        }else if(status == UPPER_CASE){
            if(src[count] == '-'){
                status = UPPER_RANGE;
            }else{
                dst[dount++] = queue;
                queue = src[count];
                status = DEFAULT;
            }
        }else if(status == NUMBER){
            if(src[count] == '-'){
                status = NUMBER_RANGE;
            }else{
                dst[dount++] = queue;
                queue = src[count];
                status = DEFAULT;
            }
        }else if(status == LOWER_RANGE){
            if(src[count] >= 'a' && src[count] <= 'z'){
                for(char eont = queue; eont <= src[count] && dount < dst_len;++eont){
                    dst[dount++] = eont;
                }
                queue = '\0';
            }else{
                queue = src[count];
            }
            status = DEFAULT;
        }else if(status == UPPER_RANGE){
            if(src[count] >= 'A' && src[count] <= 'Z'){
                for(char eont = queue; eont <= src[count] && dount < dst_len;++eont){
                    dst[dount++] = eont;
                }
                queue = '\0';
            }else{
                queue = src[count];
            }
            status = DEFAULT;
        }else if(status == NUMBER_RANGE){
            if(src[count] >= '0' && src[count] <= '9'){
                for(char eont = queue; eont <= src[count] && dount < dst_len;++eont){
                    dst[dount++] = eont;
                }
                queue = '\0';
            }else{
                queue = src[count];
            }
            status = DEFAULT;
        }
    }
    dst[dount] = '\0';
}