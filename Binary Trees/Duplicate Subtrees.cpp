// gfg potd 4th july 2024

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating veactor of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

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
        string currVal = "";
        currVal += ip[i];

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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

void preorder(Node* root, vector<int>& temp) {
    if (!root) {
        return;
    }
    // cout<<root->data<<" ";
    temp.push_back(root->data);
    preorder(root->left, temp);
    preorder(root->right, temp);
}


// } Driver Code Ends
class Solution {
  public:
    vector<Node*> printAllDups(Node* root) {
        unordered_map<string, int> subtreeMap;
        unordered_map<int, int> countMap;
        vector<Node*> duplicates;
        int id = 1;
        findDups(root, subtreeMap, countMap, duplicates, id);
        return duplicates;
    }

    string findDups(Node* node, unordered_map<string, int>& subtreeMap,
        unordered_map<int, int>& countMap, vector<Node*>& duplicates, int& id) {
            
        if (!node) return "#";

        string left = findDups(node->left, subtreeMap, countMap, duplicates, id);
        string right = findDups(node->right, subtreeMap, countMap, duplicates, id);
        
        string subtree = to_string(node->data) + "," + left + "," + right;

        if (subtreeMap.find(subtree) == subtreeMap.end()) {
            subtreeMap[subtree] = id++;
        }
        
        int subtreeId = subtreeMap[subtree];
        countMap[subtreeId]++;
        
        if (countMap[subtreeId] == 2) {
            duplicates.push_back(node);
        }
        
        return to_string(subtreeId);
    }
};

//{ Driver Code Starts.

int main() {

    int tc;
    cin >> tc;
    while (tc--) {

        string treeString;
        getline(cin >> ws, treeString);

        Node* root = buildTree(treeString);
        Solution obj;
        vector<Node*> res = obj.printAllDups(root);

        vector<vector<int>> ans;

        for (int i = 0; i < res.size(); i++) {
            vector<int> temp;
            preorder(res[i], temp);
            ans.push_back(temp);
        }

        sort(ans.begin(), ans.end());

        for (int i = 0; i < ans.size(); i++) {
            for (int j = 0; j < ans[i].size(); j++) {
                cout << ans[i][j] << " ";
            }
            cout << "\n";
        }
        // cout<<"\n";
    }
    return 0;
}

// } Driver Code Ends