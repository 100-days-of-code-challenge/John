/*

Given N friends, each one can remain single or can be paired up with some other friend. Each friend can be paired only once. Find out the total number of ways in which friends can remain single or can be paired up.
Note: Since answer can be very large, return your answer mod 10^9+7.


Example 1:

Input:N = 3
Output: 4
Explanation:
{1}, {2}, {3} : All single
{1}, {2,3} : 2 and 3 paired but 1 is single.
{1,2}, {3} : 1 and 2 are paired but 3 is single.
{1,3}, {2} : 1 and 3 are paired but 2 is single.
Note that {1,2} and {2,1} are considered same.

*/




#include <iostream>

using namespace std;

class Solution
{
public:

    int find_nc2(int n){
        return (n*(n-1)) /2;
    }

    int countFriendsPairings(int n) 
    { 
        int mem[n+1];
        mem[0]= 1;
        mem[1]= find_nc2(n);


        for(int i=2; i<=n/2; i++) {
            mem[i]= (mem[i-1] * find_nc2(n-((i-1)*2)) ) / i;
        }

        int res= 0;
        for (int i=0; i<=n/2; i++) {
            res+=mem[i];
            res= res%1000000007;
        }
        return res;
    }
};  


int main() {

    Solution s;

    int num;

    while(true) {
        cin >> num;
        cout << "Res of "<< num << " is "<< s.countFriendsPairings(num) << "\n";
    }

    return 0;


}