#include<iostream>
using namespace std;

class Node{ // THIS IS TREENODE
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
void preorder(Node* root){
    if(root == NULL) return; // BASE CASE
    cout<<root->val<<" "; // ROOT
    preorder(root->left); // LEFT
    preorder(root->right); // RIGHT
}
void inorder(Node* root){
    if(root == NULL) return; // BASE CASE
    inorder(root->left); // LEFT
    cout<<root->val<<" "; // ROOT
    inorder(root->right); // RIGHT
}
void postorder(Node* root){
    if(root == NULL) return; // BASE CASE
    postorder(root->left); // LEFT
    postorder(root->right); // RIGHT
    cout<<root->val<<" "; // ROOT
}

int main(){
    Node* a = new Node(1);
    Node* b = new Node(22);
    Node* c = new Node(3);
    Node* d = new Node(4);
    Node* e = new Node(5);
    Node* f = new Node(6);
    Node* g = new Node(7);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;
    cout<<endl;
    preorder(a);
    cout<<endl;
    inorder(a);
    cout<<endl;
    postorder(a);
}