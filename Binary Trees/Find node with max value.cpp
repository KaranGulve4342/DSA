#include<iostream>
using namespace std;

class Node{ // this is a TreeNode
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val){
            this->val = val;
            this->left = NULL;
            this->right = NULL;
        }
};

void displayTree(Node* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}
/*
int maxInTree(Node* root){
    if(root == NULL) return INT_MIN;
    int lMax = maxInTree(root->left);
    int rMax = maxInTree(root->right);
    return max(root->val ,max(lMax, rMax));
}
*/

int maxInTree(Node* root){
    if(root == NULL) return INT64_MIN;
    return max(root->val ,max(maxInTree(root->left), maxInTree(root->right)));
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(39);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(9);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    displayTree(a);
    cout<<"\n";
    cout<<maxInTree(a);
}