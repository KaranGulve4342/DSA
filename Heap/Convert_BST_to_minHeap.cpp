#include<iostream>
#include<vector>

using namespace std;

class TreeNode{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val){
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};

void inorderTraversal(TreeNode* root, vector<TreeNode*>& result){
    if(root == NULL) return;

    inorderTraversal(root->left, result);
    result.push_back(root);
    inorderTraversal(root->right, result);
}

void heapify(vector<TreeNode*>& arr, int n, int i){
    int smallest = i;
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;

    if(leftChild < n && arr[leftChild]->val < arr[smallest]->val){
        smallest = leftChild;
    }

    if(rightChild < n && arr[rightChild]->val < arr[smallest]->val){
        smallest = rightChild;
    }

    if(smallest != i){
        swap(arr[i], arr[smallest]);
        heapify(arr, n, smallest);
    }
}

void minHeap(vector<TreeNode*>& arr){
    int n = arr.size();
    for(int i = (n/2) - 1;i >= 0;i--){
        heapify(arr,n,i);
    }
}

void convertBSTtoMinHeap(TreeNode* root){
    vector<TreeNode*> nodes;
    inorderTraversal(root, nodes);

    minHeap(nodes);

    // reconstruct the BST from minHeap
    for(int i = 0;i < nodes.size();i++){
        TreeNode* current = nodes[i];

        int leftIndex = 2*i + 1;
        int rightIndex = 2*i + 2;

        current->left = (leftIndex < nodes.size()) ? nodes[leftIndex] : NULL; 
        current->right = (rightIndex < nodes.size()) ? nodes[rightIndex] : NULL; 
    }
}

// Helper Function to print the tree in an in-order traversal
void printINOrder(TreeNode* root){
    if(root == NULL) return;

    printINOrder(root->left);
    cout<<root->val<<" ";
    printINOrder(root->right);
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(6);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(7);

    cout<<"Original BST : ";
    printINOrder(root);
    cout<<endl;

    convertBSTtoMinHeap(root);

    cout<<"BST converted to MinHeap : ";
    printINOrder(root);
    cout<<endl;
    return 0;
}