#include<iostream>
#include<queue>
#include<unordered_map>
using namespace std;

class Node{ // This is a TreeNode
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

Node* construct(int arr[], int n){
    queue<Node*> q;
    Node* root = new Node(arr[0]);
    q.push(root);
    int i = 1;
    int j = 2;
    while(q.size()> 0 && i < n){
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

        if(l != NULL) q.push(l);
        if(r != NULL) q.push(r);

        i += 2;
        j += 2;
    }
    return root;
}
int levels(Node* root){
    if(root == NULL) return 0;
    return 1 + max(levels(root->left), levels(root->right));
}
void nthLevel(Node* root, int curr, int level){
    if(root == NULL) return; // base case
    if(curr == level){
        cout<<root->val<<" "; // root
        return;
    }
    nthLevel(root->left, curr+1, level); // left
    nthLevel(root->right, curr+1, level); // right
}
void levelOrder(Node* root){
    int n = levels(root);
    for(int i = 0;i < n;i++){
        nthLevel(root,1,i);
        cout<<endl;
    }
}
void topview(Node* root){
    unordered_map<int,int> m; // <level, root->val>
    queue<pair<Node*,int>>q; // <Node, level>
    pair<Node*, int> r;
    r.first = root;
    r.second = 0;
    q.push(r);
    while(q.size() > 0){
        Node* temp=  (q.front()).first;
        int level = (q.front()).second;
        q.pop();
        if(m.find(level) == m.end()){
            m[level] = temp->val;
        }
        if(temp->left != NULL){
            pair<Node*, int> p;
            p.first = temp->left;
            p.second = level - 1;
            q.push(p);
        }
        if(temp->right != NULL){
            pair<Node*, int> p;
            p.first = temp->right;
            p.second = level + 1;
            q.push(p);
        }
    }
}


int main(){
    // construct
    int arr[] = {1,2,3,4,5,INT_MIN,6,INT_MIN,INT_MIN,7,INT_MIN,INT_MIN,8};
    int n = sizeof(arr)/sizeof(arr[0]);
    Node* root = construct(arr,n);
    levelOrder(root);
    topview(root);
}