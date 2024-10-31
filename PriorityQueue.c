#include <stdio.h>
#include <stdlib.h>

// define structure for elements in priority queue
typedef struct {
    int element;
    int priority;
} PriorityQueueElement;

//define a struct for priority queue 
typedef struct {
    PriorityQueueElement *elements;
    int capacity;
    int size;
} PriorityQueue;
//function to make priority queue
PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue *pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->elements = (PriorityQueueElement*)malloc(sizeof(PriorityQueueElement) * capacity);
    pq->capacity = capacity;
    pq->size = 0;
    return pq;
}

//function to enqueue
void enqueue(PriorityQueue *pq, int element, int priority) {
    if (pq->size == pq->capacity) {
        printf("Priority Queue is full.\n");
        return;
    }
    pq->elements[pq->size].element = element;
    pq->elements[pq->size].priority = priority; //enque element w priority
    pq->size++;
}

//dequeue element with highest priority
void dequeue(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }
    int highestPriority = 5; 
    int index = -1;
    for (int i = 0; i < pq->size; i++) {
        if (pq->elements[i].priority < highestPriority) {
            highestPriority = pq->elements[i].priority;
            index = i;
        }
    }
    if (index != -1) {
        printf("Dequeued element: %d with priority: %d\n", pq->elements[index].element, pq->elements[index].priority);
        // Remove element and shift elements
        for (int i = index; i < pq->size - 1; i++) {
            pq->elements[i] = pq->elements[i + 1];
        }
        pq->size--;
    }
}

//priority queue display
void displayPriorityQueue(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty.\n");
        return;
    }
    printf("Priority Queue Elements:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Element: %d, Priority: %d\n", pq->elements[i].element, pq->elements[i].priority);
    }
}

//free memory used by priority queue
void freePriorityQueue(PriorityQueue *pq) {
    free(pq->elements);
    free(pq);
}

//Main function
int main() {
    int capacity, choice;
    printf("Enter P-Queue Length: ");
    scanf("%d", &capacity);

    PriorityQueue *pq = createPriorityQueue(capacity);

    while (1) {
        printf("\nPriority Queue Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int element, priority;
                printf("Enter element: ");
                scanf("%d", &element);
                printf("Enter priority (1 to 5): ");
                scanf("%d", &priority);
                if (priority < 1 || priority > 5) {
                    printf("Priority should be between 1 and 5.\n");
                } else {
                    enqueue(pq, element, priority);
                }
                break;
            }
            case 2: {
                dequeue(pq);
                break;
            }
            case 3: {
                displayPriorityQueue(pq);
                break;
            }
            case 4: {
                freePriorityQueue(pq);
                printf("Exiting program.\n");
                return 0;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    }
}