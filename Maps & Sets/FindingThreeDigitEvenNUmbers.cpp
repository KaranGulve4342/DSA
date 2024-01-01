// LEETCODE 2094

/*
class Solution{
public:
    vector<int> findzevenNumbers(vector<int>& arr){
        int n = arr.size();
        vector<int> ans;
        unordered_map<int, int> m;
        for(int ele : arr){
            s.insert(ele);
        }
        for(int i = 100;i <= 999;i += 2){
            int x = i;
            int a = x%10; // ones place digit
            x /= 10;
            int b = x%10; // tens place digit
            x /= 10;
            int c = x;
            if(m.find(a) != m.end()){
                m[a]--;
                if(m[a] == 0) m.erase(a);
                if(m.find(b) != m.end()) ans.push_back(i);
                m[b]++;
            }
            m[a]++;
        }
    }
    return ans;
}
*/