#include <iostream>
#include <vector>

using namespace std;

void DFSRec(vector<int> mat[], int N, int M, int i, int j)
{
    mat[i][j] = 2;
    if(j+1 < M)
    {
        if(mat[i][j+1] == 1)
        {
            DFSRec(mat, N, M, i, j+1);
        }
    }
    if(j-1 >= 0)
    {
        if(mat[i][j-1] == 1)
        {
            DFSRec(mat, N, M, i, j-1);
        }
    }
    if(i-1 >= 0)
    {
        if(mat[i-1][j] == 1)
        {
            DFSRec(mat, N, M, i-1, j);
        }
    }
    if(i+1 < N)
    {
        if(mat[i+1][j] == 1)
        {
            DFSRec(mat, N, M, i+1, j);
        }
    }
    if(i+1 < N && j+1 < M)
    {
        if(mat[i+1][j+1] == 1)
        {
            DFSRec(mat, N, M, i+1, j+1);
        }
    }
    if(i+1 < N && j-1 >= 0)
    {
        if(mat[i+1][j-1] == 1)
        {
            DFSRec(mat, N, M, i+1, j-1);
        }
    }
    if(i-1 >= 0 && j-1 >= 0)
    {
        if(mat[i-1][j-1] == 1)
        {
            DFSRec(mat, N, M, i-1, j-1);
        }
    }
    if(i-1 >= 0 && j+1 < M)
    {
        if(mat[i-1][j+1] == 1)
        {
            DFSRec(mat, N, M, i-1, j+1);
        }
    }
}

int findIslands(vector<int> mat[], int N, int M) 
{
    int count = 0;
    
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
        {
            if(mat[i][j] == 1)
            {
                DFSRec(mat, N, M, i, j);
                count++;
            }
        }
    }
    
    return count;
}