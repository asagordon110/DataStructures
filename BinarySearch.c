#include <stdio.h>

int main()
{
    int low, high, mid, x, array[5]={2,4,5,6,8};
    printf("Enter value to find, then press enter: ");
    scanf("%d", &x);
    low = 0;
    high = 4;
    mid = (low+high)/2;
    while(low<=high){
        if(array[mid]<x)
            low = mid+1;
            else if(array[mid]){
                printf("%d found at location %d in the list", x, mid+1);
                break;
            }
            else
            high = mid - 1;
            mid = (low+high)/2;
    }
        if(low>high)
        printf("Not found! %d isn't present in the list",x);
        return 0;
        }
    

    
