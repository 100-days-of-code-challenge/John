/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

stack<TreeNode *> s;


void insert_left(TreeNode *root) {
    if(!root) return;
    s.push(root);
    insert_left(root->left);
}

BSTIterator::BSTIterator(TreeNode *root) {
    // s.clear();
    while(!s.empty())
        s.pop();
    insert_left(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
    return !s.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
    TreeNode *cur_node= s.top();
    s.pop();
    insert_left(cur_node->right);
    return cur_node->val;
}

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
