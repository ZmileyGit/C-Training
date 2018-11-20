#include <stdio.h>

#define STACK_SIZE 100
#define STACK_LIMIT_REACHED "Push task failed - Stack limit reached\n"
#define EMPTY_STACK_POP "Pop task failed - Empty stack, returning 0\n"
#define EMPTY_STACK_PEEK "Peek task failed - Empty stack, returning 0\n"

static double stack[STACK_SIZE];
static int stack_position = 0;

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