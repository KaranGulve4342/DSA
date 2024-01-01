//LEETCODE 450

/*
TreeNode* iop(ListNode* root){
    TreeNode* pred = root->left;
    while(pred->right != NULL){
        pred = pred->right;
    }
    return pred;
}
TreeNode* ios(ListNode* root){
    TreeNode* suc = root->right;
    while(suc->left != NULL){
        suc = suc->left;
    }
    return suc;
}
TreeNode* deleteNode(TreeNode* root,int key){
    if(root == NULL) return NULL;
    if(root->val == key){
        // case 1 : No child
        if(root->left == NULL && root->right == NULL) return NULL;

        // case 2 : 1 child Node
        if(root->left == NULL || root->right == NULL){
            if(root->left != NULL) return root->left;
            else return root->right;
        }

        // case 3 : 2 child Node
        if(root->left != NULL && root->right != NULL){
            // Replace the root with its inorder pred/suc after replacing delete the pred/suc
            TreeNode* pred = iop(root);
            root->val = pred;
            root->left = deleteNode(root->left, pred->val);
        }
    }
    else if(root->val > key){
        // go left
        root->left = deleteNode(root->left,key);
    }
    else{   // root->val < key : go right
        root->right = deleteNode(root->right,key);
    }
    return root;
};

*/