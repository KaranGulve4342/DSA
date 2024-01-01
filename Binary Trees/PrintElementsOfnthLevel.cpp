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

int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}

void nthLevel(Node* root, int curr, int level){
    if(root == NULL) return;    // base case
    if(curr == level) cout<<root->val<<" ";   //  root
    nthLevel(root->right,curr+1, level);   //  right
    nthLevel(root->left,curr+1, level);    //  left
}

void nthLevelRev(Node* root, int curr, int level){
    if(root == NULL) return;    // base case
    nthLevel(root->right,curr+1, level);   //  right
    if(curr == level) cout<<root->val<<" ";   //  root
    nthLevel(root->left,curr+1, level);    //  left
}

void levelOrder(Node* root){
    int n = levels(root);
    for(int i = 1;i <= n;i++){
        nthLevel(root ,1 ,i);
        cout<<endl;
    }
}

void levelOrderRev(Node* root){
    int n = levels(root);
    for(int i = 1;i <= n;i++){
        nthLevelRev(root ,1 ,i);
        cout<<endl;
    }
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
    // nthLevel(a,1,2);
    levelOrder(a);
    levelOrderRev(a);

   
}