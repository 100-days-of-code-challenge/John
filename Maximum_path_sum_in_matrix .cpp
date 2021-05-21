/*Given a NxN matrix of positive integers. There are only three possible moves from a cell Matrix[r][c].

    Matrix [r+1] [c]
    Matrix [r+1] [c-1]
    Matrix [r+1] [c+1]

Starting from any column in row 0, return the largest sum of any of the paths up to row N-1.
*/

#include <algorithm>
#include <iostream>
#include <vector>
#define INT_MIN -999999

using namespace std;

class Solution
{
    public:
    int maximumPath(int N, vector<vector<int>> mat)
    {
        for(int i = 1; i < N; i++)
        {
            mat[i][0] += max(mat[i - 1][0], mat[i - 1][1]);
            
            for(int j = 1; j < N - 1; j++)
            {
                
                mat[i][j] += max(
                                    mat[i - 1][j - 1], 
                                    max(mat[i - 1][j], mat[i - 1][j + 1])
                                );
            }
            
            mat[i][N - 1] += max(mat[i - 1][N - 2], mat[i - 1][N - 1]);
        }
        
        int res = INT_MIN;
        for(int j = 0; j < N; j++)
        {
            res = max(res, mat[N - 1][j]);
        }
        
        return res;
    }
};