// LEETCODE 1233

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        // Sort the folders lexicographically
        sort(folder.begin(), folder.end());

        vector<string> ans;
        
        // Push the first folder into the result as the base
        ans.push_back(folder[0]);

        // Iterate through the sorted list of folders
        for(int i = 1; i < folder.size(); i++) {
            // Check if the current folder is NOT a subfolder of the last folder in the result
            // The folder[i] should not start with the previous folder followed by a "/"
            if (folder[i].compare(0, ans.back().size(), ans.back()) != 0 || folder[i][ans.back().size()] != '/') {
                ans.push_back(folder[i]);
            }
        }

        return ans;
    }
};
