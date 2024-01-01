/*
1. go right once
2. keep going left if possible

pseudocode: 

if(root->right == NULL) return NULL;
Node* suc = root->right;
while(suc->left != NULL){
    suc = suc->left;
}
return suc;
*/