/*

Given two strings s and t. Find the minimum number of operations that need to be performed on str1 to convert it to str2. The possible operations are:

    Insert
    Remove
    Replace

 

Example 1:

Input: 
s = "geek", t = "gesek"
Output: 1
Explanation: One operation is required 
inserting 's' between two 'e's of str1.


*/

#include <iostream>

using namespace std;


class Solution
{
    public:
    int editDistance(string str1, string str2)
    {
        int n = str1.size();
        int m = str2.size();
        
        int dp[n + 1][m + 1] = {{0}};
        
        for(int i = 0; i <= n; i++)
        {
            dp[i][0] = i;
        }
        
        for(int j = 0; j <= m; j++)
        {
            dp[0][j] = j;
        }
        
        for(int i = 1; i <= n; i++)
        {
            for(int j = 1; j <= m; j++)
            {
                if(str1[i - 1] == str2[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = 1 + min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
                }
            }
        }
        
        return dp[n][m];
    }
};