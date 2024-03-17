// LEETCODE 3085

class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char ch : word)
            freq[ch]++;
        
        vector<int> frequencies;
        for (auto& [ch, f] : freq)
            frequencies.push_back(f);
        
        sort(frequencies.begin(), frequencies.end(), greater<int>());
        
        int minDel = INT_MAX;
        
        for (int i = 0; i < frequencies.size(); ++i) {
            int target = frequencies[i];
            int del = 0;
            
            for (int j = 0; j < frequencies.size(); ++j) {
                if (frequencies[j] > target + k)
                    del += frequencies[j] - (target + k);
                else if (frequencies[j] < target)
                    del += frequencies[j];
            }
            
            minDel = min(minDel, del);
            
            if (minDel == 0)
                break;
        }
        
        return minDel == INT_MAX ? 0 : minDel;
    }
};