#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    class node{
        public:
        int vertex;
        vector<int>adj;
    };
    void dfs(int i, vector<bool>&visited, node* graph){
                
        visited[i]=true;
        for( auto k : graph[i].adj){
            if(!visited[k]){
                dfs(k,visited,graph);
            }
        }
    }   

    int makeConnected(int n, vector<vector<int>>& con) {
        int numcon=con.size();
        if(numcon<n-1){return -1;}
        vector<bool>visited(n,false);
        node graph[n];
        for(int i=0;i<n;i++){
            graph[i].vertex=i;
        }
        for(int i=0;i<con.size();i++){
            graph[con[i][0]].vertex=con[i][0];
            graph[con[i][0]].adj.push_back(con[i][1]);
            graph[con[i][1]].adj.push_back(con[i][0]);
        }
        int ct=0;
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                ct++;
                dfs(i,visited,graph);
            }
            
        }
        return ct-1;
    }
};
