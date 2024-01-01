#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
    Node(int key){
        data = key;
        left = NULL;
        right = NULL;
    }
};
void bottomView(Node* root){
    queue<pair<Node*, int>>q;
    map<int,int> mp;

    q.push({root, 0});

    while(!q.empty()){
        auto value = q.front();
        q.pop();

        mp[value.second] = value.first->data;

        if(value.first->left != NULL) q.push({value.first->left,value.second});
        if(value.first->right != NULL) q.push({value.first->right, value.second});

        vector<int> ans;

        for(auto x:mp){
            ans.push_back(x.second);
        }
        for(auto x:ans) cout<<x<<" ";
    }
}
int main(){
    Node* root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(22);
    root->left->left = new Node(5);
    root->left->right = new Node(3);
    root->right->left = new Node(4);
    root->right->right = new Node(25);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(14);
    
    bottomView(root);
}