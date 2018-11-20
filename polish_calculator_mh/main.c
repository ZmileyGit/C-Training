#include <stdio.h>
#include <math.h>
#include <ctype.h>
#include <stdlib.h>
#include "operators.h"
#include "parser.h"
#include "stack.h"

#define BUFFER_SIZE 100
#define UNKNOWN_OPERATION "Unknown operation - [%s]\n"
#define POP_PRINT_FORMAT "> %g\n"
#define PEEK_PRINT_FORMAT "= %g\n"
#define DIVISION_BY_ZERO "Division by zero\n"
#define ASSIGN_VARIABLE "%s = %g\n"
#define UNKNOWN_VARIABLE "Unknown variable - [%s]\n"

double variables['z' - 'a' + 1];

int main(){
    char buffer[BUFFER_SIZE];
    int oper;
    double right, left;

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