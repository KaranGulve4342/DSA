#include<iostream>
#include<queue>
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
void nthLevel(Node* root, int curr, int level){
    if(root == NULL) return; // base case
    if(curr == level) cout<<root->val<<" "; // ROOT
    nthLevel(root->left, curr + 1, level); // LEFT
    nthLevel(root->right, curr + 1, level); // RIGHT
}
void nthLevelOptimized(Node* root, int curr,int level){
    if(root == NULL) return; // BASE CASE
    if(curr == level){
        cout<<root->val<<" "; // ROOT
        return;
    }
    nthLevelOptimized(root->left, curr+1, level);
    nthLevelOptimized(root->right, curr+1, level);
}
void nthLevelOptimizedRev(Node* root, int curr, int level){
    if(root == NULL) return; // BASE CASE
    if(curr == level){
        cout<<root->val<<" "; // ROOT
        return;
    }
    nthLevelOptimizedRev(root->right, curr+1, level);
    nthLevelOptimizedRev(root->left, curr+1, level);
}
int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void levelOrder(Node* root){
    int n = levels(root);
    for(int i = 1;i <= n;i++){
        // nthLevel(root, 1, i);
        nthLevelOptimized(root, 1, i);
        cout<<endl;
    }
}
void levelOrderQueue(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0){
        Node* temp=  q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->left != NULL) q.push(temp->left);
        if(temp->right != NULL) q.push(temp->right);
    }
    cout<<endl;
}
void levelOrderQueueRev(Node* root){
    queue<Node*> q;
    q.push(root);
    while(q.size() > 0){
        Node* temp=  q.front();
        q.pop();
        cout<<temp->val<<" ";
        if(temp->right != NULL) q.push(temp->right);
        if(temp->left != NULL) q.push(temp->left);
    }
    cout<<endl;
}
int main(){
    Node* a = new Node(1);
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
    cout<<endl;
    
    // level Order Traversal
    levelOrderQueue(a);
    levelOrderQueueRev(a);

}