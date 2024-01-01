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
Node* construct(int arr[], int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size() > 0 && i < n){
        Node* temp = q.front();
        q.pop();
        Node* l;
        Node* r;
        if(arr[i] != INT_MIN) l = new Node(arr[i]);
        else l = NULL;
        if(j != n && arr[j] != INT_MIN) r = new Node(arr[j]);
        else r = NULL;

        temp->left = l;
        temp->right = r;

        if(l!=NULL) q.push(l);
        if(r!=NULL) q.push(r);

        i+=2;
        j+=2;
    }
    return root;
}
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
void nthLevelOptimized(Node* root, int curr ,int level){
    if(root == NULL) return; // BASE CASE
    if(curr == level){
        cout<<root->val<<" "; // ROOT
        return;
    }
    nthLevelOptimized(root->left, curr+1, level);
    nthLevelOptimized(root->right, curr+1, level);
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

void leftBoundry(Node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    cout<<root->val<<" ";
    leftBoundry(root->left);
    if(root->left == NULL) leftBoundry(root->right);
}

void bottomBoundry(Node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) cout<<root->val<<" ";
    bottomBoundry(root->left);
    bottomBoundry(root->right);
}

void rightBoundry(Node* root){
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL) return;
    rightBoundry(root->right);
    if(root->right == NULL) rightBoundry(root->left);
    cout<<root->val<<" ";
}

void Boundry(Node* root){
    leftBoundry(root);
    bottomBoundry(root);
    rightBoundry(root);
}
int main(){
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);

    // construct
    Node* root = construct(arr,n);

    Boundry(root);

    levelOrder(root);




}