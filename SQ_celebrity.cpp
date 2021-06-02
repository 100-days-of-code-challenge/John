#include <iostream>
#include <vector>

using namespace std;

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        for(int i=0; i<n; i++) {
            M[i][i]= 1;
        }

    }
};



