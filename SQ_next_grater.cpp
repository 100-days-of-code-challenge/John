#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution
{
    public:
    //Function to find the next greater element for each element of the array.
    vector<long long> nextLargerElement(vector<long long> arr, int n){
        
        vector<long long> res;

        stack<long long> stk;

        res.insert(res.begin(), -1);
        stk.push(arr[arr.size()-1]);

        for(int i=arr.size()-2; i>=0; i--) {
            long long cur_item= arr[i];
            while(!stk.empty() && stk.top() < cur_item) stk.pop();

            if(stk.empty()) res.insert(res.begin(), -1);
            else res.insert(res.begin(), stk.top());
            
            stk.push(cur_item);
        }

        return res;

    }
};

