//  LEETCODE 110

#include<iostream>
using namespace std;

class Node{
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

int getLevels(Node* root){
    if(root == NULL) return true;
    return 1 + max(getLevels(root->left), getLevels(root->right));
}

bool isBalanced(Node* root){
    if(root == NULL) return true;
    return abs(getLevels(root->left) - getLevels(root->right)) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}    

int main(){
    Node* a = new Node(1);
    Node* b = new Node(2);
    Node* c = new Node(3);
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
    cout<<isBalanced(a);
}