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

void find_result(Node *root, int height, vector<int> &result) {
    if(!root) return;
    if(height > result.size())
        result.push_back(root->data);
    find_result(root->left, height+1, result);
    find_result(root->right, height+1, result);
}

vector<int> leftView(Node *root)
{
   // Your code here
   vector<int> result;
   find_result(root, 1, result);
   return result;
}



int main() {



	return 0;
}
