#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define BUFFER_SIZE 100
#define UNKNOWN_OPERATION "Unknown operation - [%s]\n"
#define POP_PRINT_FORMAT "> %g\n"
#define PEEK_PRINT_FORMAT "= %g\n"
#define DIVISION_BY_ZERO "Division by zero\n"
#define ASSIGN_VARIABLE "%s = %g\n"
#define UNKNOWN_VARIABLE "Unknown variable - [%s]\n"
enum operators{
    PUSH = '>',
    ADD = '+',
    SUBSTRACT = '-',
    DIVIDE = '/',
    MODULUS = '%',
    POP = '\n',
    PEEK = '=',
    MULTIPLY = '*',
    DUPLICATE = '!',
    SWAP = '<',
    CLEAR = '?',
    POW = -10,
    EXP = -11,
    SIN = -12,
    ASSIGN = -13,
    SUBSTITUTE = -14
};

#define STACK_SIZE 100
#define STACK_LIMIT_REACHED "Push task failed - Stack limit reached\n"
#define EMPTY_STACK_POP "Pop task failed - Empty stack, returning 0\n"
#define EMPTY_STACK_PEEK "Peek task failed - Empty stack, returning 0\n"
double stack[STACK_SIZE];
int stack_position = 0;
double pop(void);
void push(double value);
void clear(void);
double peek(void);

#define QUEUE_SIZE 10
#define EMPTY_QUEUE_DEQUEUE "Dequeue task failed - Empty queue, returning 0\n"
#define FULL_QUEUE_ENQUEUE "Enqueue task failed - Queue limit reached\n"
char queue[QUEUE_SIZE];
int queue_head = 0;
int queue_next = 0;
int queue_size = 0;
void enqueue(char value);
void enqueue_str(char str[]);
char dequeue(void);

int get_next_oper(char buffer[],int size);
enum status{
    NORMAL,
    OPERAND,
    OPERATOR,
    INTEGER,
    FRACTION,
    NEGATIVE,
    LETTER,
    S_FILTER,
    SI_FILTER,
    E_FILTER,
    EX_FILTER,
    P_FILTER,
    PO_FILTER,
    DOLLAR,
    VARIABLE
};

double variables['z' - 'a' + 1];

int main(){
    char buffer[BUFFER_SIZE];
    int oper;
    double right, left;

    double sin(double x);
    double pow(double x,double y);
    double exp(double x);

    while((oper = get_next_oper(buffer,BUFFER_SIZE)) != EOF){
        switch(oper){
            case PUSH:
                push(atof(buffer));
            break;
            case ADD:
                push(pop() + pop());
            break;
            case SUBSTRACT:
                right = pop();
                push(pop() - right);
            break;
            case MULTIPLY:
                push(pop() * pop());
            break;
            case DIVIDE:
                right = pop();
                if(right != 0.0){
                    push(pop() / right);
                }else{
                    printf(DIVISION_BY_ZERO);
                    clear();
                }
            break;
            case MODULUS:
                right = pop();
                if(right != 0.0){
                    push((int)pop() % (int)right);
                }else{
                    printf(DIVISION_BY_ZERO);
                    clear();
                }
            break;
            case DUPLICATE:
                push(peek());
            break;
            case SWAP:
                right = pop();
                left = pop();
                push(right);
                push(left);
            break;
            case SIN:
                push(sin(pop()));
            break;
            case EXP:
                push(exp(pop()));
            break;
            case POW:
                right = pop();
                push(pow(pop(),right));
            break;
            case ASSIGN:
                if(islower(buffer[0])){
                    left = peek();
                    variables[buffer[0] - 'a'] = left;
                    printf(ASSIGN_VARIABLE,left,buffer);
                }else{
                    printf(UNKNOWN_VARIABLE,buffer);
                }
            break;
            case SUBSTITUTE:
                if(islower(buffer[0])){
                    push(variables[buffer[0] - 'a']);
                }else{
                    printf(UNKNOWN_VARIABLE,buffer);
                }
            break;
            case CLEAR:
                clear();
            case POP:
                printf(POP_PRINT_FORMAT,pop());
            break;
            case PEEK:
                printf(PEEK_PRINT_FORMAT,peek());
            break;
            default:
                printf(UNKNOWN_OPERATION,buffer);
            break;
        }
    }
    return 0;
}

int get_next_oper(char buffer[],int size){
    int cursor;
    int count = 0, status = NORMAL;
    while((queue_size > 0) || ((cursor = getchar()) != EOF)){
        if(queue_size > 0){
            cursor = dequeue();
        }
        if(status == NORMAL){
            if(isdigit(cursor) || cursor == '.'){
                status = OPERAND;
                enqueue(cursor);
            }else if(cursor == ' ' || cursor == '\t'){
                status = NORMAL;
            }else if(cursor == '-'){
                status =  NEGATIVE;
            }else if(islower(cursor)){
                status = LETTER;
                enqueue(cursor);
            }else if(cursor == '$'){
                status = DOLLAR;
            }else{
                status = OPERATOR;
                enqueue(cursor);
            }
        }else if(status == DOLLAR){
            if(islower(cursor)){
                buffer[count++] = cursor;
                buffer[count++] = '\0';
                return ASSIGN;
            }else{
                status = NORMAL;
                enqueue(cursor);
            }
        }else if(status == VARIABLE){
            if(islower(cursor)){
                buffer[count++] = cursor;
                buffer[count++] = '\0';
                return SUBSTITUTE;
            }else{
                status = OPERATOR;
                enqueue(cursor);
            }
        }else if(status == LETTER){
            if(cursor == 's'){
                status = S_FILTER;
            }else if(cursor == 'e'){
                status = E_FILTER;
            }else if(cursor == 'p'){
                status = P_FILTER;
            }else{
                status = VARIABLE;
                enqueue(cursor);
            }
        }else if(status == S_FILTER){
            if(cursor == 'i'){
                status = SI_FILTER;
            }else{
                status = VARIABLE;
                enqueue('s');
                enqueue(cursor);
            }
        }else if(status == SI_FILTER){
            if(cursor == 'n'){
                return SIN;
            }else{
                status = VARIABLE;
                enqueue_str("si");
                enqueue(cursor);
            }
        }else if(status == E_FILTER){
            if(cursor == 'x'){
                status = EX_FILTER;
            }else{
                status = VARIABLE;
                enqueue('e');
                enqueue(cursor);
            }
        }else if(status == EX_FILTER){
            if(cursor == 'p'){
                return EXP;
            }else{
                status = VARIABLE;
                enqueue_str("ex");
                enqueue(cursor);
            }
        }else if(status == P_FILTER){
            if(cursor == 'o'){
                status = PO_FILTER;
            }else{
                status = VARIABLE;
                enqueue('p');
                enqueue(cursor);
            }
        }else if(status == PO_FILTER){
            if(cursor == 'w'){
                return POW;
            }else{
                status = VARIABLE;
                enqueue_str("po");
                enqueue(cursor);
            }
        }else if(status == NEGATIVE){
            buffer[count++] = '-';
            if(isdigit(cursor)){
                status = INTEGER;
                enqueue(cursor);
            }else if(cursor == '.'){
                status = FRACTION;
                enqueue(cursor);
            }else{
                enqueue(cursor);
                buffer[count++] = '\0';
                return '-';
            }
        }else if(status == OPERAND){
            if(isdigit(cursor)){
                status = INTEGER;
                enqueue(cursor);  
            }else if(cursor == '.'){
                status = FRACTION;
                enqueue(cursor);
            }
        }else if(status == OPERATOR){
            buffer[count++] = cursor;
            buffer[count++] = '\0';
            return cursor;
        }else if(status == INTEGER){
            if(isdigit(cursor)){
                buffer[count++] = cursor;
            }else if(cursor == '.'){
                status = FRACTION;
                enqueue(cursor);
            }else{
                enqueue(cursor);
                return PUSH;
            }
        }else if(status = FRACTION){
            if(cursor == '.'){
                buffer[count++] = cursor;
            }else if(isdigit(cursor)){
                buffer[count++] = cursor;
            }else{
                enqueue(cursor);
                return PUSH;
            }
        }
    }
    return EOF;
}

double peek(void){
    if(stack_position > 0){
        return stack[stack_position - 1];
    }else{
        printf(EMPTY_STACK_PEEK);
        return 0.0;
    }
}

double pop(void){
    if(stack_position > 0){
        return stack[--stack_position];
    }else{
        printf(EMPTY_STACK_POP);
        return 0.0;
    }
}

void push(double value){
    if(stack_position < STACK_SIZE){
        stack[stack_position++] = value;
    }else{
        printf(STACK_LIMIT_REACHED);
    }
}

void clear(void){
    stack_position = 0;
}

void enqueue(char value){
    if(queue_size < QUEUE_SIZE){
        queue[queue_next] = value;
        queue_next = (queue_next + 1) % QUEUE_SIZE;
        queue_size++;
    }else{
        printf(FULL_QUEUE_ENQUEUE);
    }
}

void enqueue_str(char str[]){
    for(int count = 0;str[count] != '\0';++count){
        enqueue(str[count]);
    }
}

char dequeue(void){
    if(queue_size > 0){
        char result = queue[queue_head];
        queue_head = (queue_head + 1) % QUEUE_SIZE;
        queue_size--;
        return result;
    }else{
        printf(EMPTY_QUEUE_DEQUEUE);
    }
    return '\0';
}