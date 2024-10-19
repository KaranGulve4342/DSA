#include<bits/stdc++.h>
using namespace std;


bool getPath(TreeNode* root, vector<int>& ans, int x){
    if(root == false){
        return false;
    }

    ans.push_back(root->val);

    if(root->val == x){
        return true;
    }

    if(getPath(root->left, ans, x) || getPath(root->right, ans, x)){
        return true;
    }

    ans.pop_back();

    return false;
}
vector<int> solve(TreeNode* A, int B){
    vector<int> ans;

    if(A ==  NULL){
        return ans;
    }

    getPath(A, ans, B);
    return ans;
}