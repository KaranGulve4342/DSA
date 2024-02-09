// LEETCODE 116

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void connectNodes(Node* leftNode, Node* rightNode){
        if(leftNode == NULL || rightNode == NULL) return;

        leftNode->next = rightNode;

        connectNodes(leftNode->left, leftNode->right);
        connectNodes(leftNode->right, rightNode->left);
        connectNodes(rightNode->left, rightNode->right);
    }
    Node* connect(Node* root) {
        if(root == NULL) return root;

        connectNodes(root->left, root->right);
        return root;
    }
};