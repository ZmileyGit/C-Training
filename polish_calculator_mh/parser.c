#include "queue.h"
#include "operators.h"
#include <ctype.h>
#include <stdio.h>

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

extern int queue_size;

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