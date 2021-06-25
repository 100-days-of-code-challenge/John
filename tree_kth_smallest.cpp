/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


void inorder(TreeNode *r, vector<int> &res) {
    if(!r) return;

    inorder(r->left, res);
    res.push_back(r->val);
    inorder(r->right, res);

    
}

int Solution::kthsmallest(TreeNode* A, int B) {

    vector<int> res;
    inorder(A, res);
    return res[B-1];
}