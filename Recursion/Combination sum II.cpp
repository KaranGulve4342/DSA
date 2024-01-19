// LEETCODE 40

/*
class Solution{
private:
    void helper(int idx, vector<int>& candidates, int target, vector<int> &ds, vector<vector<int> >&combination){
        if(target == 0){
            combination.push_back(ds);
            return;
        }

        for(int i = idx;i < candidates.size();i++){
            if(i > idx && candidates[i-1] == candidates[i]) continue;
            if(candidates[i] > target) break;

            ds.push_back(candidates[idx]);
            helper(i + 1, candidates, target - candidates[i], ds, combination);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target){
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > combination;
        vector<int> ds;

        helper(0, candidates, target, ds, combination);

        return combination;
    }
}
*/