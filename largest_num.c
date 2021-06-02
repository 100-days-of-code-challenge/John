#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int get_len(int n) {
	int res= 0;
	while(n) {
		res++;
		n/=10;
	}
	return res;
}

int comp(int n1, int n2){

	int n1_len= get_len(n1);
	int n2_len= get_len(n2);
	long long int x1= n1*pow(10, n2_len)+n2;
	long long int x2= n2*pow(10, n1_len)+n1;
	return x1<x2? 1:0;
}

void special_sort(int *orig, int size) {
	for(int i=0; i<size; i++) {
		for(int j=0; j<size-1; j++) {
			if(comp(orig[j], orig[j+1])) {
				int tmp= orig[j];
				orig[j]= orig[j+1];
				orig[j+1]= tmp;
			}
		}
	}
}

char * largestNumber(int* nums, int numsSize){

	int tot_str_len= 0, max_num= -1;

	for(int i=0; i<numsSize; i++) {
		if(nums[i]>max_num)
			max_num= nums[i];
		tot_str_len+= get_len(nums[i]);
	}

	int max_len= get_len(max_num);

	special_sort(nums, numsSize);

	char *res=(char *) malloc(sizeof(char)*(tot_str_len+1));
	res[0]= '\0';

	char buff[20];
	for(int i=0; i<numsSize; i++) {
		sprintf(buff, "%d", nums[i]);
		strcat(res, buff);
	}

	return res;

}



int main() {

	int arr[]= {1,2,3,4,5,6,7,8,9,0};

	printf("\n%s", largestNumber(arr, 10));



	return 0;
}


