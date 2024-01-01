#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    
    return 0;
}
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
}; 
class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    void inorder(Node* root, vector<int> &result){
        if(root == NULL) return;
        inorder(root->left, result);
        result.push_back(root->data);
        inorder(root->right, result);
    }
    Node* helper(vector<int> &result, int lo, int hi){
        if(lo > hi) return NULL;
        int mid = lo + (hi - lo)/2;
        Node* root = new Node(result[mid]);
        root->left = helper(result, lo, mid-1);
        root->right = helper(result, mid + 1, hi);
        return root;
    }
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> result;
        inorder(root, result);
        sort(result.begin(),result.end());
        int n = result.size();
        return helper(result,0,n-1);
    }
};