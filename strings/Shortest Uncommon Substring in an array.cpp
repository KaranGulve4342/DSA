// LEETCODE 3076

class Solution {
public:
    vector<string> shortestSubstrings(vector<string>& arr) {
        auto generateSubstr = [](const string& s) {
            vector<string> subStrings;
            for (int i = 0; i < s.length(); ++i) {
                for (int j = i + 1; j <= s.length(); ++j) {
                    subStrings.push_back(s.substr(i, j - i));
                }
            }
            sort(subStrings.begin(), subStrings.end(), [](const string& a, const string& b) {
                return a.length() < b.length() || (a.length() == b.length() && a < b);
            });
            return subStrings;
        };
        
        int n = arr.size();
        vector<string> ans(n, "");

        for (int i = 0; i < n; ++i) {
            vector<string> Substrings = generateSubstr(arr[i]);
            for (const string& str : Substrings) {
                bool unique = true;
                for (int j = 0; j < n; ++j) {
                    if (i != j && arr[j].find(str) != string::npos) {
                        unique = false;
                        break;
                    }
                }
                if (unique) {
                    ans[i] = str;
                    break;
                }
            }
        }
        
        return ans;
    }
};