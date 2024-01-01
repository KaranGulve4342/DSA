/*
class Solution{
public:
    int countNodes(struct Node* root){
        // base case
        if(root == NULL){
            return 0;
        }
        int ans = 1 + countNodes(root->left) + countNodes(root->right);
        return ans;
    }
    bool isCBT(struct Node* root, int index, int count){
        if(root = NULL){
            return true;
        }
        if(root >= count){
            return false;
        }
        else{
            bool left = isCBT(root->left, 2*index + 1, count);
            bool right = isCBT(root->right, 2*index + 2, count);
            return (left && right);
        }
    }
    bool isMaxOrder(struct Node* root){
        if(root->left == NULL && root->right == NULL){
            return true;
        }
        if(root->right == NULL){
            return (root->data > root->right->data);
        }
        else{
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);

            return (left && right && (root->data > root->left->data && root->data > root->right->data));
        }
    }
    bool isHeap(struct Node*tree){
        int index = 0;
        int totalCount = countNodes(tree);
        if(isCBT(tree, index, totalCount) && isMaxOrder(tree)){
            return true;
        }
        else{
            return false;
        }
    }
};
*/