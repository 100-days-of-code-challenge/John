#include <iostream>


using namespace std;

void swap(int *a, int *b){
    *a= *a+*b;
    *b= *a-*b;
    *a= *a-*b;
}

void sort012(int arr[], int n) {
	int last_0_ind= -1, first_2_ind= n;
    for(int i=0; i<n; i++) {
        while(arr[first_2_ind-1] == 2) first_2_ind--;
        if( i >= first_2_ind) break;
        if(arr[i] == 0) {
            swap(&arr[i], &arr[++last_0_ind]);
        }
        else if(arr[i] == 2) {
            swap(&arr[i], &arr[--first_2_ind]);
        }
    }
}


int main() {

	int arr[]= {0,1,0,2,2,0,1,0,2,0,0,0,1,1,0,2};
	int len= sizeof(arr)/sizeof(arr[0]);

	sort012(arr, len);

	for(int i=0; i<len; i++) {
		cout << arr[i] << " ";
	}



	return 0;
}
