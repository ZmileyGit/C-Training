#include <stdio.h>
#include <ctype.h>

#define QUEUE_LIMIT 10
#define FULL_QUEUE "Full Queue\n"
#define EMPTY_QUEUE "Empty Queue\n"

char queue[QUEUE_LIMIT];
int queue_size = 0;
int queue_head = 0;
int queue_tail = 0;

enum parser_status{
    NORMAL,
    FINISH,
    NUMBER,
    FRACTION,
    NEGATIVE,
    POSITIVE,
    DOT
};

void enqueue(char value);
char dequeue(void);
int getint(int *dst);
int getdouble(double *dst);

int main(){
    double num = 0.0f;
    while(getdouble(&num) != EOF){
        printf("%f\n",num);
        num = 0;
    }
    return 0;
}

int getdouble(double *dst){
    int cursor = 0;
    int status = NORMAL;
    short sign = 0;
    double fraction = 0;
    long exponent = 1;
    while(status != FINISH && (queue_size > 0 || (cursor = getchar()) != EOF)){
        if(queue_size > 0){
            cursor = dequeue();
        }
        switch(status){
            case NORMAL:
                if(isspace(cursor)){
                    status = NORMAL;
                }else if(isdigit(cursor)){
                    status = NUMBER;
                    sign = 1;
                    enqueue(cursor);
                }else if(cursor == '-'){
                    status = NEGATIVE;
                }else if(cursor == '+'){
                    status = POSITIVE;
                }else if(cursor == '.'){
                    status = DOT;
                }else{
                    status = FINISH;
                    enqueue(cursor);
                }
            break;
            case NUMBER:
                if(isdigit(cursor)){
                    *dst = (10.0 * (*dst)) + (cursor - '0');
                }else if(cursor == '.'){
                    status = DOT;
                }else{
                    status = FINISH;
                    *dst *= sign;
                    enqueue(cursor);
                }
            break;
            case FRACTION:
                if(isdigit(cursor)){
                    fraction = (fraction * 10.0) + (cursor - '0');
                    exponent *= 10;
                }else{
                    status = FINISH;
                    *dst += (fraction/exponent);
                    *dst *= sign;
                    enqueue(cursor);
                }
            break;
            case NEGATIVE:
                if(isdigit(cursor)){
                    status = NUMBER;
                    sign = -1;
                    enqueue(cursor);
                }else if(cursor == '.'){
                    status = DOT;
                }else{
                    status = FINISH;
                    enqueue('-');
                    enqueue(cursor);
                }
            break;
            case POSITIVE:
                if(isdigit(cursor)){
                    status = NUMBER;
                    sign = 1;
                    enqueue(cursor);
                }else if(cursor == '.'){
                    status = DOT;
                }else{
                    status = FINISH;
                    enqueue('+');
                    enqueue(cursor);
                }
            break;
            case DOT:
                if(isdigit(cursor)){
                    status = FRACTION;
                    if(!sign)
                        sign = 1;
                    enqueue(cursor);
                }else{
                    status = FINISH;
                    switch(sign){
                        case 1:
                            enqueue('+');
                        break;
                        case -1:
                            enqueue('-');
                        break;
                    }
                    enqueue('.');
                    enqueue(cursor);
                }
            break;
        }
    }
    return cursor;  
}

int getint(int *dst){
    int cursor = 0;
    int status = NORMAL;
    short sign = 1;
    while(status != FINISH && (queue_size > 0 || (cursor = getchar()) != EOF)){
        if(queue_size > 0){
            cursor = dequeue();
        }
        switch(status){
            case NORMAL:
                if(isspace(cursor)){
                    status = NORMAL;
                }else if(isdigit(cursor)){
                    status = NUMBER;
                    enqueue(cursor);
                }else if(cursor == '-'){
                    status = NEGATIVE;
                }else if(cursor == '+'){
                    status = POSITIVE;
                }else{
                    status = FINISH;
                    enqueue(cursor);
                }
            break;
            case NUMBER:
                if(isdigit(cursor)){
                    *dst = (10 * (*dst)) + (cursor - '0');
                }else{
                    status = FINISH;
                    *dst = (*dst) * sign;
                    enqueue(cursor);
                }
            break;
            case NEGATIVE:
                if(isdigit(cursor)){
                    status = NUMBER;
                    sign = -1;
                    enqueue(cursor);
                }else{
                    status = FINISH;
                    enqueue('-');
                    enqueue(cursor);
                }
            break;
            case POSITIVE:
                if(isdigit(cursor)){
                    status = NUMBER;
                    enqueue(cursor);
                }else{
                    status = FINISH;
                    enqueue('+');
                    enqueue(cursor);
                }
            break;
        }
    }
    return cursor;
}


void enqueue(char value){
    if(queue_size < QUEUE_LIMIT){
        queue[queue_tail] = value;
        queue_tail = (queue_tail + 1) % QUEUE_LIMIT;
        queue_size++;
    }else{
        printf(FULL_QUEUE);
    }
}

char dequeue(void){
    if(queue_size > 0){
        char result = queue[queue_head];
        queue_head = (queue_head + 1) % QUEUE_LIMIT;
        queue_size--;
        return result;
    }
    printf(EMPTY_QUEUE);
    return '\0';
}