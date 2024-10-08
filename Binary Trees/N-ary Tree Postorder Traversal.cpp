// LEETCODE 590



/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        if(root == NULL){
            return {};
        }

        vector<int> ans;

        stack<Node*> st;

        st.push(root);
        while(!st.empty()){
            Node* t = st.top();
            st.pop();

            for(int i = 0;i < t->children.size();i++){
                st.push(t->children[i]);
            }

            ans.push_back(t->val);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};