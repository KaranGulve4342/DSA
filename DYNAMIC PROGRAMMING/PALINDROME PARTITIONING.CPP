// LEETCODE 131

/*
class Solution{
public:
    bool isPalindrome(string s, int left, int right){
        if(s[left++] != s[right--]){
            return false;
        }
    }
    return true;
}

void solve(string s, int index, vector<vector<string> >&ans, vector<string>& result){
    if(index == s.size()){
        ans.push_back(result);
        return;
    }

    for(int i = index;i < s.size();i++){
        if(isPalindrome(s, index, i){
            result.push_back(s.substr(index, i-index+1));
            solve(s, i+1, ans, result);
            result.pop_back();
        }
    }
}

vector<vector<string> > partition(string s){
    vector<vector<string> > ans;
    vector<string> result;
    solve(s, 0, ans, result);
    return ans;
}
*/