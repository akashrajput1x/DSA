#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int* array;
    int no_of_values;
    int size;
};

struct Queue* getQueue(int size){
    struct Queue* temp = (struct Queue*)malloc(sizeof( struct Queue));
    temp->array = (int*)malloc(size*sizeof(int));
    temp->size = size;
    temp->no_of_values = 0;
    return temp;
}

void enqueue(struct Queue* ptr,int val){
    if(ptr->no_of_values<ptr->size){
        ptr->array[ptr->no_of_values] = val;
        ptr->no_of_values++;
    }else{
        printf("Queue is full\n");
    }
}

int dequeue(struct Queue* ptr){
    if(ptr->no_of_values == 0){
        printf("Queue is empty\n");
    }else{
        int dequeue_val = ptr->array[0];
        for(int i=0;i<ptr->no_of_values-1;i++){
            ptr->array[i] = ptr->array[i+1];
        }
        ptr->no_of_values--;
        return dequeue_val;
    }
}

void printQueue(struct Queue* ptr){
    for(int i=0;i<ptr->no_of_values;i++){
        printf("%d, ",ptr->array[i]);
    }
    printf("\n");
}

int main(){
    struct Queue* queue = getQueue(10);
    dequeue(queue);
    for(int i=0;i<15;i++){
        enqueue(queue, i*100);
    }
    printQueue(queue);
    dequeue(queue);
    printQueue(queue);
}