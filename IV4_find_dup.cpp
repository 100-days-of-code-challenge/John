#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;


int find_dup(int *arr, int size) {

	int sqrt_size= (sqrt(size)) +2;
	int hash_table[sqrt_size]= {0};

	for(int i=0; i<size; i++) {
		int el= arr[i];
		int hashed_ind= el%sqrt_size;
		int pos= pow(2,  el/sqrt_size);

		if((hash_table[hashed_ind] & pos)) {
			return el;
		}
		hash_table[hashed_ind] |= pos;
	}

	return -1;

}


int find_dup_compact(int *arr, int size) {
	int hash_table[sqrt(size) +2]= {};
	for(int i=0; i<size; i++)
		if(hash_table[arr[i]%(sqrt(size) +2)] & pow(2,  arr[i]/(sqrt(size) +2))) return arr[i];
		else hash_table[arr[i]%(sqrt(size) +2)] |= pow(2,  arr[i]/(sqrt(size) +2));
	return -1;
}





int main() {

	int arr[] ={ 1,2,3,4,5,3,4};

	int size= sizeof(arr)/ sizeof(arr[0]);

	cout << find_dup(arr, size) << endl;



	return 0;
}
