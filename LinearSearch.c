#include <stdio.h>

int main(){
    //declaration of the array and other variables
    int arr[20],size,key,i,index;
    printf("Number of elements in the list: ");
    scanf("%d", size);
    printf("Enter elements of the list");
    //loop for the input of elements from 0 to number of elements -1
    for(int i=0;i<size;i++){
        scanf("%d,&arr[i]");
    }
    printf("Enter the element to search/key element: ");
    scanf("%d",&key);
    //loop for traversing array from 0 to the num of elements 
    for(index=0;index<size;index++){
        if(arr[index]==key) //comparing each element with the key element
        break; //cursor out of the loop when a key element is found
        if(index <size) //condition to check whether previous loops partially traversed or not
        printf("Key element found at index %d",index); 
        else
        printf("Key element not found\n");
}
        return 0;
    
    }
    #include <stdio.h>
//Linear search example #2
int search(int array[], int n, int x)
{
    for (int i=0;i<n;i++)
    if(array[i]==x)
    return i;
    return -1;
}
int main(){
    int array[] = {2,4,0,1,9};
    int x;
    printf("Enter a number to search: ");
    scanf("%d",&x);
    //int x =1
    int n = sizeof(array)/sizeof(array[0]);
    int result = search(array,n,x);
    if(result ==-1)
    printf("element not found\n");
    else
    printf("Element found at index: %d", result);
    return 0;
}
