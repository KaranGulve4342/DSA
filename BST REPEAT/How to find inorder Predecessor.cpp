/*
1. go left once
2. keep going right

pseudocode:


if(root->left == NULL) return NULL;
Node* pred = root->left;
while(pred->right != NULL){
    pred = pred->right;
}
return pred;
*/