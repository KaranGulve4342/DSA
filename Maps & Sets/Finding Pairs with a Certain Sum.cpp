// LEETCODE 1865

/*
class FindSumPairs {
public:
    unordered_map<int, int> mp;
    vector<int> a,b;

    FindSumPairs(vector<int>& nums1, vector<int>& nums2){
        for(auto x : nums2){
            mp[x]++;
        }
        a = nums1;
        b = nums2;
    }

    void add(int index, int val){
        mp[b[index]]--;
        b[index] += val;
        mp[b[index]]++;
    }

    int count(int tot){
        int ans = 0;
        for(int i = 0;i < a.size();i++){
            int x = tot - a[i];
            if(mp.find(x) != mp.end()) ans += mp[x];
        }
        return ans;
    }
}
*/