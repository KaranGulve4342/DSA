// LEETCODE 1028

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 class Solution {
    public:
        TreeNode* recoverFromPreorder(string traversal) {
            stack<TreeNode*> st;
            int index = 0;
    
            while(index < traversal.length()){
                int depth = 0;
    
                while(index < traversal.length() && traversal[index] == '-'){
                    depth++;
                    index++;
                }
    
                int value = 0;
    
                while(index < traversal.length() && isdigit(traversal[index])){
                    value = value*10 + (traversal[index] - '0');
                    index++;
                }
    
                TreeNode* node = new TreeNode(value);
    
                while(st.size() > depth){
                    st.pop();
                }
    
                if(!st.empty()){
                    if(st.top()->left == NULL){
                        st.top()->left  = node;
                    }
                    else{
                        st.top()->right = node;
                    }
                }
    
                st.push(node);
            }
    
            while(st.size() > 1){
                st.pop();
            }
            return st.top();
        }
    };