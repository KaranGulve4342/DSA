#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to count BST subtrees that lie in the given range [low, high]
int countRangeBSTSubtrees(TreeNode* root, int low, int high, int& count) {
    if (root == nullptr) {
        return 0;
    }

    // Recursively count subtrees in the left and right subtrees
    int leftCount = countRangeBSTSubtrees(root->left, low, high, count);
    int rightCount = countRangeBSTSubtrees(root->right, low, high, count);

    // Check if the current node's value is within the range [low, high]
    if (root->val >= low && root->val <= high) {
        // If it is, increment the count and return the sum of counts from left and right subtrees plus 1
        count++;
        return leftCount + rightCount + 1;
    } else {
        // If not, return 0 and do not increment the count
        return 0;
    }
}

int main() {
    // Example binary search tree
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(7);
    root->right->right = new TreeNode(18);

    int low = 7;
    int high = 15;
    int count = 0;

    // Count BST subtrees that lie in the range [low, high]
    countRangeBSTSubtrees(root, low, high, count);

    cout << "Number of BST subtrees in the range [" << low << ", " << high << "]: " << count << endl;

    return 0;
}
