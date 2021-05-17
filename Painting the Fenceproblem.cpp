
Given a fence with n posts and k colors, find out the number of ways of painting the fence such that at most 2 adjacent posts have the same color. Since answer can be large return it modulo 10^9 + 7.


Example 1:

Input:
N=3,  K=2 
Output: 6






#include <iostream>
#include <vector>


using namespace std;



long long countWays(int n, int k){
	vector<vector<int>> mem(n+1, vector<int> (3, 0));

	mem[0][2]=k;
	mem[1][2]=k*(k-1);
	mem[2][2]=mem[0][2]+mem[1][2];

	for (int j = 3; j < n+1; j++) {
		mem[0][j]=(mem[1][j-1])%1000000009;
		mem[1][j]=(mem[2][j-1]*(k-1))%1000000009;
		mem[2][j]=(mem[0][j]+mem[1][j])%1000000009;
	}
	return mem[2][n];
}

int main() {

	int n=3, k=2;

	cout << countWays(n,k);



	return 0;
}
