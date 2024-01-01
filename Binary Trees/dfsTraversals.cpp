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

// PreOrder Traversal
void preOrder(Node* root){
    if(root == NULL) return;    // base case
    cout<<root->val<<" ";   //  root
    preOrder(root->left);    //  left
    preOrder(root->right);   //  right
}
// InOrder Traversal
void InOrder(Node* root){
    if(root == NULL) return;    // base case
    InOrder(root->left);    //  left
    cout<<root->val<<" ";   //  root
    InOrder(root->right);   //  right
}
// PostOrder Traversal
void PostOrder(Node* root){
    if(root == NULL) return;    // base case
    PostOrder(root->left);    //  left
    PostOrder(root->right);   //  right
    cout<<root->val<<" ";   //  root
}

int main(){
    Node* a = new Node(1);  // root
    Node* b = new Node(2);
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

    preOrder(a);
    cout<<endl;
    InOrder(a);
    cout<<endl;
    PostOrder(a);
    cout<<endl;
}