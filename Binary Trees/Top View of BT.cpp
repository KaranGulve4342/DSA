#include<bits/stdc++.h>
using namespace std;


struct Node
{
    int data;
    Node* left;
    Node* right;
};


vector<int> topView(Node* root){
    vector<int> ans;


    if(root == NULL){
        return ans;
    }

    mpa<int, int> topNode;

    queue<pair<Node*, int>> q;

    q.push({root, 0});

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        if(topNode.find(hd) == topNode.end()){
            topNode[hd] = frontNode->data;
        }

        if(frontNode->left != NULL){
            q.push({frontNode->left, hd-1});
        }
        if(frontNode->right != NULL){
            q.push({frontNode->right, hd+1});
        }
    }

    for(auto it : topNode){
        ans.push_back(it.second);
    }

    return ans;
}

