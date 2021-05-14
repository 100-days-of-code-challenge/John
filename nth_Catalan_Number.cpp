#include <iostream>


using namespace std;


class Solution
{
	public:
	long long int nth_catalan( int n ) {

		long long int mem[n+1]= {0};
		mem[0]= 1;
		mem[1]= 1;

		for(int cur_num=2; cur_num<=n; cur_num++) {
			long long int cat= 0;
			for(int i=0; i<cur_num; i++) {
				cat+= mem[i]*mem[cur_num-i-1];
			}
			mem[cur_num]= cat;
		}

		return mem[n];

	}

};

int main() {

	Solution s;

	for(int i=0; i<20; i++) {
		cout <<i << "th Catelen_number: "<< s.nth_catalan(i) << "\n";
	}



	return 0;
}
