// LEETCODE 1008

/*
    TreeNode* build(vector<int>& pre,int preLo,int preHi,vector<int>& in, int inLO, int inHi){
        if(preLo > preHi) return NULL;
        TreeNode* root = new TreeNode(pre[preLo]);
        if(preLo == preHi) return root;
        int i = inLo;
        while(i <= inHi){
            if(in[i] == pre[preLo]) break;
            i++;
        }
        int leftCOunt = i - inLo;
        int right = inHi - i;
        root->left = build(pre,preLo + 1,preLo + leftCount, in, inLo, i-1);
        root->right =build(pre,preLo + leftCount + 1,preHi, in, i+1, inHi);
        return root;
    }
    TreeNode* bestFromPreorder(vector<int>& pre){
        vector<int> in = pre;
        sort(in.begin(),in.end());
        int n = pre.size();
        return build(pre,0,n-1,in,0,n-1);
    }
*/

/*
class SOlution{
public:
    if(root == NULL) root = new TreeNode(val);
    else if(root->val > val){
        // go left
        if(root->left == NULL){
            // attach it here
            root->left = new TreeNode(val);
        }
        else insert(root->left, val);
    }
    else{
        // root->val < val : go right
        if(root->right == NULL){
            // attach it here
            root->right = new TreeNode(val);
        }
        else insert(root->right, val);
    }

    TreeNode* bstFromPreorder(vector<int>& pre){
        TreeNode* root = new TreeNode(pre[0]);
        for(int i = 1;i < pre.size();i++){
            insert(root,pre[i]);
        }
        return root;
    }
}
*/