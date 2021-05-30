#include <stdio.h>


void sort(int *arr, int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=i+1; j<size; j++) {
            if(arr[j]>arr[j+1]) {
                arr[j]+=arr[j+1];
                arr[j+1]= arr[j]-arr[j+1];
                arr[j]-= arr[j+1];
            }
        }
    }
}

int minSkips(int* dist, int distSize, int speed, int hoursBefore){

    int sorted[distSize];

    for(int i=0; i<distSize; i++)
        sorted[i]= dist[i]%distSize;

    sort(sorted, distSize);

    int cur_res= 0;

}