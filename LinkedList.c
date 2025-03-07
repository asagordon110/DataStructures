#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define a struct for the order
typedef struct Order {
    int orderNumber;
    char itemName[50];
    struct Order* next;
} Order;

//creates a new order node
Order* createOrder(int orderNumber, const char* itemName) {
    Order* newOrder = (Order*)malloc(sizeof(Order));
    newOrder->orderNumber = orderNumber;
    strcpy(newOrder->itemName, itemName);
    newOrder->next = NULL;
    return newOrder;
}

//add an order to the end of linked list
Order* addOrder(Order* tail, int orderNumber, const char* itemName) {
    Order* newOrder = createOrder(orderNumber, itemName);
    if (tail == NULL) {
        return newOrder;
    }
    tail->next = newOrder;
    return newOrder;
}

//displays orders in the linked list
void displayOrders(Order* head) {
    if (head == NULL) {
        printf("No orders in the list.\n");
        return;
    }

    printf("Order List:\n");
    while (head != NULL) {
        printf("Order Number: %d, Item Name: %s\n", head->orderNumber, head->itemName);
        head = head->next;
    }
}

//removes first order from the linked list 
Order* removeFirstOrder(Order* head) {
    if (head == NULL) {
        printf("No orders in the list to remove.\n");
        return NULL;
    }

    Order* newHead = head->next;
    free(head);
    return newHead;
}

//free memory used by linked list
void freeOrders(Order* head) {
    while (head != NULL) {
        Order* temp = head;
        head = head->next;
        free(temp);
    }
}

//main function
int main() {
    Order* head = NULL;
    Order* tail = NULL;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Add an order\n");
        printf("2. Display orders\n");
        printf("3. Remove the first order (FIFO)\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int orderNumber;
                char itemName[50];
                printf("Enter order number: ");
                scanf("%d", &orderNumber);
                printf("Enter item name: ");
                scanf("%s", itemName);

                tail = addOrder(tail, orderNumber, itemName);
                if (head == NULL) {
                    head = tail;
                }
                break;
            }
            case 2:
                displayOrders(head);
                break;
            case 3:
                head = removeFirstOrder(head);
                break;
            case 4:
                freeOrders(head);
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
                break;
        }
    }
}