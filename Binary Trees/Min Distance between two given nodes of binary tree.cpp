// GFG POTD 7TH FEB 2024

//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
public:
    /* Should return minimum distance between a and b
       in a tree with given root */
    int findDist(Node* root, int a, int b) {
        // Find lowest common ancestor of nodes a and b
        Node* lcaNode = findLCA(root, a, b);

        // Calculate distances from lcaNode to a and b
        int distA = findDistance(lcaNode, a, 0);
        int distB = findDistance(lcaNode, b, 0);

        // Return the sum of distances from lcaNode to a and b
        return distA + distB;
    }

private:
    // Utility function to find the lowest common ancestor of two nodes
    Node* findLCA(Node* root, int a, int b) {
        if (root == NULL || root->data == a || root->data == b)
            return root;

        Node* left = findLCA(root->left, a, b);
        Node* right = findLCA(root->right, a, b);

        // If both left and right are not NULL, it means one node is in left subtree
        // and the other is in the right subtree, so the current node is the LCA.
        if (left && right)
            return root;

        // Otherwise, return the non-NULL node
        return left ? left : right;
    }

    // Utility function to find the distance from a node to a given value
    int findDistance(Node* root, int value, int depth) {
        if (root == NULL)
            return -1;

        if (root->data == value)
            return depth;

        int left = findDistance(root->left, value, depth + 1);
        if (left != -1)
            return left;

        int right = findDistance(root->right, value, depth + 1);
        return right;
    }
};

//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends   