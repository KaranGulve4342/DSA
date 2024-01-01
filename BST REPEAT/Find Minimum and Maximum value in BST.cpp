/*

void maxAndMin(TreeNode* root){
    int min = root->val;
    int max = root->val;

    TreeNode* temp = root;
    while(temp->left != NULL){
        min = temp->left->val;
    }
    while(temp->right != NULL){
        max = temp->right->val;
    }
    return {max,min};
}

*/