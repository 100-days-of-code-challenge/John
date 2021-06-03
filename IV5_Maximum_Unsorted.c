

#include <stdio.h>
#include <stdlib.h>

int *max_unsorted(int *arr, int size, int *res_size) {
    int start_ind= size-1, end_ind= 0;

    for(int i=0; i<size; i++)
        if(arr[i] != i+1) {
            start_ind= i;
            break;
        }

    for(int i=size-1; i>=0; i--)
        if(arr[i] != i+1) {
            end_ind= i;
            break;
        }
    
    if(start_ind>end_ind) {
        int *res= (int *) malloc(sizeof(int));
        res[0]= -1;
        *res_size= 1;
        return res;
    }

    *res_size= 2;
    int *res= (int *)malloc(sizeof(int)*(*res_size));
    
    res[0]= start_ind;
    res[1]= end_ind;
    return res;
}



int main() {

    int arr[]= {1, 2, 3, 5, 4};

    int size= -1;

    int *res= max_unsorted(arr, 5, &size);

    for(int i=0; i<size; i++) {
        printf("%d ", res[i]);
    }


    return 0;
}