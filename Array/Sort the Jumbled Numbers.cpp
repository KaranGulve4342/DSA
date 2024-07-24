// LEETCODE 2191

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int, int>> vec;
        for(int i = 0;i < nums.size();i++){
            int num = nums[i];
            string number = to_string(num);
            string str = "";
            for(int j = 0;j < number.length();j++){
                str += (to_string(mapping[number[j]- '0']));
            }

            int val = stoi(str);
            vec.push_back({val, i});
        }

        sort(vec.begin(), vec.end());

        vector<int> ans;
        for(auto x : vec){
            ans.push_back(nums[x.second]);
        }

        return ans;
    }
};