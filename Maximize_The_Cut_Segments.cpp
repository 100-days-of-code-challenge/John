/*
Given an integer N denoting the Length of a line segment. You need to cut the line segment in such a way that the cut length of a line segment each time is either x , y or z. Here x, y, and z are integers.
After performing all the cut operations, your total number of cut segments must be maximum.

Example 1:

Input:
N = 4
x = 2, y = 1, z = 1
Output: 4
Explanation:Total length is 4, and the cut
lengths are 2, 1 and 1.  We can make
maximum 4 segments each of length 1.
*/





#include <iostream>


using namespace std;





class Solution {

	int max(int arr[6]){
		int max= -1;
		for(int i=0; i<6; i++) {
			if(max<arr[i])
				max= arr[i];
		}
		return max;
	}

    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
		
		int mem[n+1];

		for(int i=0; i<=n; i++){
			mem[i]= -1;
		}


		for(int cur= 1; cur<=n; cur++) {
			int res_arr[]= {-1,-1,-1,-1,-1,-1};

			if(cur-x == 0){
				res_arr[0]= 1;
			}
			else if(cur-x>0 && mem[x] >0 && mem[cur-x]>0) {
				res_arr[1]= mem[x]+ mem[cur-x];
			}
			if(cur-y == 0){
				res_arr[2]= 1;
			}
			else if(cur-y>0 && mem[y] >0 && mem[cur-y]>0) {
				res_arr[3]= mem[y]+ mem[cur-y];
			}
			if(cur-z == 0){
				res_arr[4]= 1;
			}
			else if(cur-z>0 && mem[z] >0 && mem[cur-z]>0) {
				res_arr[5]= mem[z]+ mem[cur-z];
			}
			mem[cur]= max(res_arr);
		}

		// for(int i=0; i<=n; i++){
		// 	cout << i <<" - "<< mem[i] <<"\n";
		// }

		return mem[n]>0? mem[n]:0;

    }
};


int main() {

	Solution s;

	int n= 7;
	int x=5, y=5, z=2;

	int res= s.maximizeTheCuts(n,x,y,z);

	cout <<"\n   "<< res << "\n";



	return 0;
}
