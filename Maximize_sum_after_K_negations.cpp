#include <iostream>


using namespace std;


long long int maximizeSum(long long int a[], int n, int k) {
	sort(a,a+n);
	long long smallest=1e12+5, sum=0;
	for(int i=0;i<n;i++){
		if(k=>0 ) {
			if(a[i]<0){
				a[i]=(-1)*a[i];
				k--;
			}
		}
		smallest=min(smallest,a[i]);
		sum+=a[i];
	}
	
	if(k&1) {
		sum-=(2*smallest);
	}

	return sum;
}
