#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>


using namespace std;




class Solution
{
    priority_queue<int, vector<int>, greater<int>> g;
    priority_queue<int> s;
    
    public:
    void insertHeap(int &x){
        if(s.size() > g.size()){
            int temp = x;
            if(s.top() > x){
                temp = s.top();
                s.pop();
                s.push(x);
            }
            g.push(temp);
        }else{
            int temp = x;
            if(!g.empty() && g.top() < x){
                temp = g.top();
                g.pop();
                g.push(x);
            }
            s.push(temp);
        }
    }
    
    void balanceHeaps(){
        
    }
    
    double getMedian(){
        if(s.size() > g.size()){
            return s.top();
        } else {
            return (float)(s.top() + g.top())/2;
        }
    }
};
