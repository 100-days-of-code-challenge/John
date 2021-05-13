/*

Given two integers n and r, find nCr. Since the answer may be very large, calculate the answer modulo 109+7.

Example 1:

Input: n = 3, r = 2
Output: 3
Explaination: 3C2 = 3. 

*/


#include <iostream>

using namespace std;


class Solution{
public:

    int nCr_dp(int n, int r, int **mem) {


        if(r == 0) {
            return 1;
        }
        // if(r == 1) {
        //     return n;
        // }
        if(n == r) {
            return 1;
        }
        // if(n-1 == r) {
        //     return n;
        // }

        int n_minus_one_C_r= mem[n-1][r];
        if(n_minus_one_C_r<0){
            n_minus_one_C_r= nCr_dp(n-1, r, mem);
            mem[n-1][r]= n_minus_one_C_r;
        }

        int n_minus_one_C_r_minus_one= mem[n-1][r-1];
        if(n_minus_one_C_r_minus_one<0){
            n_minus_one_C_r_minus_one= nCr_dp(n-1, r-1, mem);
            mem[n-1][r-1]= n_minus_one_C_r_minus_one;
        }
        return (n_minus_one_C_r + n_minus_one_C_r_minus_one)%1000000007;

    }

    int nCr(int n, int r){
        
        // int mem[n][r]= {-1};

        int **mem;
        mem = new int *[n+1];
        for(int i = 0; i <=n; i++) {
            mem[i] = new int[r+1];
            for(int j=0; j<=r; j++) {
                mem[i][j]= -1;
            }
        }

        return nCr_dp(n, r, mem);
        

    }
};



int main() {

    Solution s;

    int n= 10;
    int r= 5;

    cout << n << "C"<< r << "= " << s.nCr(n,r);
    return 0;
}