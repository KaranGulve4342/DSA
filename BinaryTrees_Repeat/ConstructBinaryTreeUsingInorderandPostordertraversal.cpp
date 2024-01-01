// LEETCODE 106

/*
class Solution {
public:
    TreeNode* build(vector<int>& inorder, int inLo, int inHi, vector<int>& postorder, int postLo, int postHi){
        if(inLo > inHi) return NULL;
        TreeNode* root = new TreeNode(postorder[postHi]);
        if(inLo == inHi) return root;
        int i = inLo;
        while(i <= inHi){
            if(inorder[i] == postorder[postHi]){
                break;
            }
            i++;
        }
        int leftCount = i - inLo;
        int rightCount = inHi - i;

        root->left = build(inorder, inLo, i - 1, postorder, postLo, postLo + leftCount-1);
        root->right = build(inorder, i +1, inHi, postorder, postLo + leftCount, postHi-1);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return build(inorder,0,n-1,postorder,0,n-1);
    }
};
*/