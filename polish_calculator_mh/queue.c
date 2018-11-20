#include <stdio.h>

#define QUEUE_SIZE 10
#define EMPTY_QUEUE_DEQUEUE "Dequeue task failed - Empty queue, returning 0\n"
#define FULL_QUEUE_ENQUEUE "Enqueue task failed - Queue limit reached\n"

static char queue[QUEUE_SIZE];
static int queue_head = 0;
static int queue_next = 0;
int queue_size = 0;

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