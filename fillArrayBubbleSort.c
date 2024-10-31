//This program fills an array with random numbers, sorts them using a bubble sort, and then displays the sorted list
#include <stdio.h>
#define MAX 10

int a[MAX];
int rand_seed=10;
int rand()
{
    rand_seed = rand_seed *100;
    return (unsigned int)(rand_seed/10) % 11;
}

void main(){
    int i,t,x,y;
    //fill array
    for(i=0;i<MAX;i++){
        a[i]=rand();
        printf("Unsorted %d: %d\n",i,a[i]);
    }
    //bubble sort the array
    for(x=0;x<MAX-1;x++){
        for(y=0;y<MAX-x-1; y++){
            if(a[y] > a[y+1]){
                t=a[y];
                a[y]=a[y+1];
                a[y+1]=t;
            }

        }
    }
    //print sorted array
    printf("----------------\n");
    for(i=0;i<MAX;i++)
    printf("Sorted %d:%d\n",i,a[i]);
    return 0;
}