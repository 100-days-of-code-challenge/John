/*

Given a value N, find the number of ways to make change for N cents, if we have infinite supply of each of S = { S1, S2, .. , SM } valued coins. 

Example 1:

Input:
n = 4 , m = 3
S[] = {1,2,3}
Output: 4
Explanation: Four Possible ways are:
{1,1,1,1},{1,1,2},{2,2},{1,3}.

*/


#include <iostream>
using namespace std;


class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        long long int mem[n + 1] = {0};
        mem[0] = 1;
        for(int i = 0; i < m; i++) {
            for(int j = S[i]; j <= n; j++) {
                mem[j] += mem[j - S[i]];
            }
        }
        return mem[n];
    }
};



int main() {
    Solution s;
    int n=4;
    int m=3;
    int S[]= {1,2,3};
    long long res= s.count(S, m, n);

    cout  <<"Res: " <<res;
}