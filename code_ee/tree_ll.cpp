#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Node {

	public:
	int val;
	Node *left, *right;

	Node(int data) {
		val= data;
		left= right= NULL;
	}

};


Node * tree_to_ll(Node *root, Node *head, Node *cur) {

	if(!root) return;

	head= tree_to_ll(root->left, head, cur);
	if(!head) {
		head= root;
		head->left= head->right= NULL;
		return head;
	}
	Node *tmp_right= root->right;
	cur->right= root;
	root->left= cur;
	root->right= NULL;
	cur= root;
	
}





int main() {



	return 0;
}
