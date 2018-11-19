#include <stdio.h>

#define QUEUE_SIZE 8

int queue[QUEUE_SIZE];
int next = 0;
int head = 0;
int size = 0;

void enqueue(int value);
int dequeue();

int main(){
    printf("Enqueue\n");
    for(int count = 0;count < QUEUE_SIZE * 2;++count){
        printf("N: %d, H: %d, S: %d\n",next,head,size);
        enqueue(count);
        
    }
    printf("Dequeue\n");
    for(int count = 0;count < QUEUE_SIZE / 2;++count){
        printf("N: %d, H: %d, S: %d\n",next,head,size);
        printf("%d\n",dequeue());
    }
    printf("Enqueue\n");
    for(int count = 0;count < QUEUE_SIZE;++count){
        printf("N: %d, H: %d, S: %d\n",next,head,size);
        enqueue(count);
        
    }
    printf("N: %d, H: %d, S: %d\n",next,head,size);
    return 0;
}

void enqueue(int value){
    if(size < QUEUE_SIZE){
        queue[next] = value;
        next = (next + 1) % QUEUE_SIZE;
        size++;
    }else{
        printf("The queue is full\n");
    }
}

int dequeue(){
    if(size > 0){
        int result = queue[head];
        head = (head + 1) % QUEUE_SIZE;
        size--;
        return result;
    }
    printf("The queue is empty\n");
    return 0.0;
}