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


vector<int> bottom_view(Node *head) {

    

}