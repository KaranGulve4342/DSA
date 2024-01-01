// LEETCODE 2385

/*
class Solution{
public:
    TreeNode* first = NULL;
    void markParent(TreeNode* root, unordered_map<TreeNode*, treeNode*>& parent){
        if(root == NULL) return;
        if(root->left != NULL) parent[root->left] = root;
        if(root->right != NULL) parent[root->right] = root;
        markParent(root->left, parent);
        markParent(root->right, parent);
    }
    void find(TreeNode* root, int start){
        if(root == NULL) return;
        if(root->val == start){
            first = root;
            return;
        }
        find(root->left, start);
        find(root->right, start);
    }
    int amountOfTime(TreeNode* root, int start){
        find(root, start);
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);
        unordered_set<TreeNode*> s;
        s.insert(first);
        queue<pair<treeNode*, int>>q;
        q.push({first,0});
        int maxLevel = 0;
        // bfs
        while(q.size() > 0){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            int level = p.second;
            maxLevel = max(maxLevel, level);
            TreeNode* temp = p.first;
            if(temp->left != NULL){
                if(s.find(temp->left) == s.end()){
                    q.push({temp->left, level+1});
                    s.insert(temp->left);
                }
            }
            if(temp->right != NULL){
                if(s.find(temp->right) == s.end()){
                    q.push({temp->right, level+1});
                    s.insert(temp->right);
                }
            }
            if(parent.find(temp) != parent.end()){
                if(s.find(parent[temp]) == s.end()){
                    q.push({parent[temp],level+1});
                    s.insert(parent[temp]);
                }
            }

        }
        return maxLevel;

    }
}
*/