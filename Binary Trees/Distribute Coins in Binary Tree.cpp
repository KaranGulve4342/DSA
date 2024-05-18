// LEETCODE 979


#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int solve(TreeNode* root, int &moves){
        if(root == NULL) return 0;

        int leftCoins = solve(root->left, moves);
        int rightCoins = solve(root->right, moves);

        int coins = leftCoins + rightCoins;

        if(root->val == 0){
            coins -= 1;
        }
        else if(root->val == 1){
            coins += 0;
        }
        else{
            coins += (root->val - 1);
        }

        moves += abs(coins);
        return coins;

    }
    int distributeCoins(TreeNode* root) {
        int moves = 0;

        solve(root, moves);
        return moves;
    }
};