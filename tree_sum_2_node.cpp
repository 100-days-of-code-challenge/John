/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

void inorder(TreeNode *t, vector<int> &v) {
    if(!t) return;

    inorder(t->left, v);
    v.push_back(t->val);
    inorder(t->right, v);
}


int Solution::t2Sum(TreeNode* A, int B) {

    vector<int> arr;
    inorder(A, arr);

    int l_ptr= 0;
    int r_ptr= arr.size()-1;

    while(l_ptr<r_ptr) {
        int val= arr[l_ptr] + arr[r_ptr];
        if(val == B) return 1;
        else if(val>B) r_ptr--;
        else if(val<B) l_ptr++;
    }
    return 0;
}