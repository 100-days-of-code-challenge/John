#include <iostream>
#include <vector>
#include <string>

using namespace std;


struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    void find_result(Node *root, int height, vector<int> &result) {
        if(!root) return;
        if(height > result.size())
            result.push_back(root->data);
        find_result(root->right, height+1, result);
        find_result(root->left, height+1, result);
    }
    vector<int> rightView(Node *root)
    {
       // Your Code here
       vector<int> result;
       find_result(root, 1, result);
       return result;
    }
};



int main() {



	return 0;
}
