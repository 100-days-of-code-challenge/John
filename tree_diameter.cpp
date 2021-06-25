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

class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    
    
    int get_height(Node *root, int &max_diff) {
        
        if(!root) return 0;
        
        int l_height= get_height(root->left, max_diff);
        int r_height= get_height(root->right, max_diff);
        
        int diff= l_height+r_height;
        if(diff>max_diff)
            max_diff= diff;
        
        return max(l_height, r_height)+1;
    }
    
    int diameter(Node* root) {
        // Your code here
        
        int diam= 0;
        get_height(root, diam);
        
        return diam+1;        
    }
};




int main() {



	return 0;
}
