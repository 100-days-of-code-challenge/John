/*On an N x N board, the numbers from 1 to N*N are written boustrophedonically starting from the bottom left of the board, and alternating direction each row.  For example, for a 6 x 6 board, the numbers are written as follows:


You start on square 1 of the board (which is always in the last row and first column).  Each move, starting from square x, consists of the following:

    You choose a destination square S with number x+1, x+2, x+3, x+4, x+5, or x+6, provided this number is <= N*N.
        (This choice simulates the result of a standard 6-sided die roll: ie., there are always at most 6 destinations, regardless of the size of the board.)
    If S has a snake or ladder, you move to the destination of that snake or ladder.  Otherwise, you move to S.
*/


#include <iostream>
#include <vector>



using namespace std;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        vector<int> arr(n*n);
        int i = n-1, j = n-2, k = 0;
        while(i >= 0 or j >= 0)
        {
            if(i >= 0)
            {
                for(int r = 0; r < n; r++)
                {
                    arr[k++] = board[i][r];
                }
                i -= 2;
            }
            if(j >= 0)
            {
                for(int r = n-1; r >= 0; r--)
                {
                    arr[k++] = board[j][r];
                }
                j -= 2;
            }
        }
        
        vector<int> visited(n*n,0);
        
        queue<pair<int, int>> q;
        q.push({0,0});
        visited[0] = 1;
        
        while(!q.empty())
        {
            pair<int, int> cell = q.front();
            q.pop();
            
            int v = cell.first;
            int dist = cell.second;
            
            if(v == (n*n)-1)
                return dist;
            
            for(i = v+1; (i <= v+6) and (i < n*n); i++)
            {
                if(!visited[i])
                {
                    pair<int, int> adj_cell = {i, dist + 1};
                    if(arr[i] != -1)
                        adj_cell.first = arr[i]-1;
                    //cout << adj_cell.first << " " << adj_cell.second << endl;
                    q.push(adj_cell);
                    visited[i] = 1;
                }
            }
            
        }
        
        return -1;
    
    }
};