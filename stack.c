/*implementing a stack
Use an array to store all the items
Use an int variable to keep track of last pushed item (most recently entered)
Check if stack is full and/or empty
*/
#include <stdio.h>
int MAXSIZE = 10;
int stack[MAXSIZE];
int top = -1;

//check if stack is empty
int isEmpty(){
    if(top == -1){
        return 1;
        return 0;
    }
}
    //check if stack is full
    int isFull(){
        if(top >= MAXSIZE){
            return 1;
            return 0;
        }
    }
//return most recently added item without removing from stack
int peek(){
    if(isEmpty()){
        printf("Error, stack is empty\n");
    }
    else{
        return stack[top];
    }
    }
//return most recently added item and delete it from the stack
int pop(){
    int data;
    if(!isEmpty){
        data = stack[top];
        top = top-1; //removes top value from stack
        return data;
    }
    else{
        printf("Could not retrieve data\n");
    }
    }

    //insert into stack
    int push(int data){
        if(!isFull){
            top = top+1;
            stack[top] = data;
        }
        else{
            printf("Could not insert\n");
        }
    }

    //main function
    int main(){
        push(13);
        push(22);
        push(8);
        push(2);

        //print last added number from the stack
        printf("Element at top of the stack: %d\n", peek());

        while(!isEmpty){
            int data = pop();
            printf("%d\n", data);
        }
    }
    


