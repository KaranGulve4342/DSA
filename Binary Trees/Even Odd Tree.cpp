// LEETCODE 1609

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
    int levels(TreeNode* root){
        if(root == NULL) return 0;
        return 1 + std::max(levels(root->left), levels(root->right));
    }
    
    void solve(TreeNode* root, vector<vector<int>>& ans, int level){
        if(root == NULL) return;
        ans[level].push_back(root->val);
        solve(root->left, ans, level+1);
        solve(root->right, ans, level+1);
    }
    
    bool isEvenOddTree(TreeNode* root) {
        int maxLevel = levels(root);
        vector<vector<int>> ans(maxLevel, vector<int>{});
        solve(root, ans, 0);

        for(int i = 0; i < maxLevel; ++i){
            if(i % 2 == 0){
                if(!checkStrictlyIncreasing(ans[i]) || !checkOdd(ans[i])){
                    return false;
                }
            } else {
                if(!checkStrictlyDecreasing(ans[i]) || !checkEven(ans[i])){
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool checkStrictlyIncreasing(vector<int>& nums){
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] <= nums[i-1]){
                return false;
            }
        }
        return true;
    }
    
    bool checkStrictlyDecreasing(vector<int>& nums){
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] >= nums[i-1]){
                return false;
            }
        }
        return true;
    }
    
    bool checkOdd(vector<int>& nums){
        for(int num : nums){
            if(num % 2 == 0){
                return false;
            }
        }
        return true;
    }
    
    bool checkEven(vector<int>& nums){
        for(int num : nums){
            if(num % 2 != 0){
                return false;
            }
        }
        return true;
    }
};