// LEETCODE 98
/*
long long maxTree(TreeNode* root){
    if(root == NULL) return LLONG_MIN;
    return max((long long)(root->val), max(maxTree(root->left), maxTree(root->right)));
}
long long minTree(TreeNode* root){
    if(root == NULL) return LLONG_MAX;
    return min((long long)(root->val), min(minTree(root->left), minTree(root->right)));
}
bool isValidBST(TreeNode* root){
    if(root == NULL) return true;
    else if((long long)(root->val) <= maxTree(root->left)) return false;
    else if((long long)(root->val) >= minTree(root->right)) return false;
    return isValidBST(root->left) && isValidBST(root->right);
}
*/



/*
class Solution{
    public:
        long long maxTree(TreeNode* root){
            if(root == NULL) return LLONG_MIN;
            return max((long long)(root->val),max(maxTree(root->left),maxTree(root->right)));
        }
        long long minTree(TreeNode* root){
            if(root == NULL) return LLONG_MAX;
            return min((long long)(root->val),min(minTree(root->left),minTree(root->right)));
        }
        bool isValidBST(TreeNode* root){
            if(root == NULL)    return true;
            else if((long long)(root->val) <= maxTree(root->left)) return false;
            else if((long long)(root->val) >= maxTree(root->right)) return false;
            return isValidBST(root->left) && isValidBST(root->right);
        }
};


*/
/*
class Solution{
    public:
        void Inorder(TreeNode* root, vector<int>& ans){
            if(root == NULL) return; // base case
            Inorder(root->left,ans); // left
            ans.push_back(root->val); // root
            Inorder(root->right,ans); // right
        }
        v
        bool isValidBST(TreeNode* root){
            vector<int> ans;
            inorder(root, ans);
            for(int i = 1;i <= ans.size();i++){
                if(ans[i] <= ans[i-1]) return false;
            }
            return true;
        }
};

*/

/*
class Solution{
    public:
        TreeNode* prev = NULL;
        bool flag = true;
        void inorder(TreeNode* root){
            if(root == NULL) return;
            inprder(root->left);
            if(prev != NULL){
                if(root->val <= prev->val){
                    flag = true;
                    return;
                }
            }
            prev = root;
            inorder(root->right);
        }
        bool isValidBST(TreeNode* root){
            inorder(root);
            return flag;
        }
};

*/

