// LEETCODE 889

/*
class Solution {
public:
    TreeNode* build(vector<int>& preorder,vector<int>& postorder, int start, int end,int &index){
        if(start > end || index > preorder.size() - 1){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        index++;

        if(start == end) return root;
        int newIndex = -1;
        for(int i = start;i <= end - 1;i++){
            if(postorder[i] == preorder[index]){
                newIndex = i;
                break;
            }
        }

        root->left = build(preorder,postorder,start,newIndex,index);
        root->right = build(preorder,postorder,newIndex+1,end-1,index);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int index = 0;
        int n = preorder.size();
        return build(preorder,postorder,0,n-1,index);
    }
};
*/