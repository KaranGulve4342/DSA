// GFG

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    int minTime(Node* root, int target) 
    {
         if (!root) return 0;

        // Step 1: Find the target node and store parent pointers
        unordered_map<Node*, Node*> parent;
        Node* targetNode = nullptr;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            Node* node = q.front(); 
            q.pop();
            if (node->data == target) {
                targetNode = node;
            }
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // Step 2: BFS to burn the tree starting from the target node
        queue<Node*> burnQueue;
        unordered_set<Node*> visited;
        burnQueue.push(targetNode);
        visited.insert(targetNode);
        int time = 0;

        while (!burnQueue.empty()) {
            int size = burnQueue.size();
            bool anyNodeBurnt = false;
            for (int i = 0; i < size; ++i) {
                Node* current = burnQueue.front();
                burnQueue.pop();

                // Burn left child
                if (current->left && visited.find(current->left) == visited.end()) {
                    burnQueue.push(current->left);
                    visited.insert(current->left);
                    anyNodeBurnt = true;
                }
                // Burn right child
                if (current->right && visited.find(current->right) == visited.end()) {
                    burnQueue.push(current->right);
                    visited.insert(current->right);
                    anyNodeBurnt = true;
                }
                // Burn parent
                if (parent.find(current) != parent.end() && visited.find(parent[current]) == visited.end()) {
                    burnQueue.push(parent[current]);
                    visited.insert(parent[current]);
                    anyNodeBurnt = true;
                }
            }
            if (anyNodeBurnt) time++;
        }

        return time;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends