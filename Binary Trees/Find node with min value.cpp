#include<iostream>
using namespace std;

class Node{ // this is a treeNode
    public:
        int val;
        Node* left;
        Node* right;
        Node(int val){
            this->val = val;
            this->left = left;
            this->right = right;
        }
};

void displayTree(Node* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}

int minInTree(Node* root){
    if(root == NULL) return INT64_MAX;
    return min(root->val,min(minInTree(root->left),minInTree(root->right)));
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
    cout<<minInTree(a);
}