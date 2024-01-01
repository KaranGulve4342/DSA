#include<iostream>
using namespace std;

class TreeNode{
    public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int val){
            this->val = val;
            this->left = left;
            this->right = right;
        }
};

void displayTree(TreeNode* root){
    if(root == NULL) return;
    cout<<root->val<<" ";
    displayTree(root->left);
    displayTree(root->right);
}

bool isSameTree(TreeNode* p,TreeNode* q){
    if(p == NULL && q == NULL) return true;
    if(p == NULL && q != NULL) return false;
    if(p != NULL && q == NULL) return false;

    if(p->val != q->val) return false;

    bool leftAns = isSameTree(p->left, q->left);
    if(leftAns == false) return false;

    bool rightAns = isSameTree(p->right, q->right);
    if(rightAns == false) return false;

    return true;
}
TreeNode* invertTree(TreeNode* root){
    if(root == NULL) return NULL;

    TreeNode* temp = root->left;
    root->left = root->right;
    root->right = temp;

    invertTree(root->left);
    invertTree(root->right);

    return root;
}

bool isSymmetric(TreeNode* root){
    if(root == NULL) return true;
    invertTree(root->left);
    
    bool flag = isSameTree(root->left,root->right);
    invertTree(root->left);
    return flag;
}

int main(){
    TreeNode* a = new TreeNode(1);
    TreeNode* b = new TreeNode(2);
    TreeNode* c = new TreeNode(3);
    TreeNode* d = new TreeNode(4);
    TreeNode* e = new TreeNode(5);
    TreeNode* f = new TreeNode(6);
    TreeNode* g = new TreeNode(9);

    a->left = b;
    a->right = c;
    b->left = d;
    b->right = e;
    c->left = f;
    c->right = g;

    displayTree(a);
    cout<<"\n";
    cout<<isSymmetric(a);

}

// Symmetric tree
/*
bool isMirror(struct Node* root1, struct Node* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    
    if (root1 && root2 && root1->data == root2->data)
        return isMirror(root1->left, root2->right)
                && isMirror(root1->right, root2->left);
    
    return false;
}
    
bool isSymmetric(struct Node* root)
{
    return isMirror(root, root);
}
 
*/