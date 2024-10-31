void printQueue(sruct queue* q){
    int i = q ->front; //print the queue
    if(isEmpty(q)){
        printf("queue is empty");
        else{
            printf("\nQueue contains \n");
            for(i =     ; i < q->rear + 1; i++){
                printf("%d ",q->items[i]);
            }
        }
    }
}
T