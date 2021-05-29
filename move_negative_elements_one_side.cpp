#include <iostream>


using namespace std;

void rearrange(int arr[], int n) {
	int last_neg_ind= -1;

	for(int i=0; i<n; i++) {
		if(arr[i]<0) {
			int tmp= arr[i];
			arr[i]= arr[++last_neg_ind];
			arr[last_neg_ind]= tmp;
		}
	}
}


int main() {

	int arr[]= {-1,2,3,-4,5,6,-7};
	int len= sizeof(arr)/sizeof(arr[0]);

	rearrange(arr, len);

	for(int i=0; i<len; i++) {
		cout << arr[i] << " ";
	}



	return 0;
}
