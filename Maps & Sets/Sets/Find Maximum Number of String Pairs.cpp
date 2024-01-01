// LEETCODE 2744

/*
class Solution{
public:
    int maximumNumberOfStringPairs(vector<string>& arr){
        int n = arr.size();
        int count = 0;
        unordered_set<string> s;
        for(int i = 0;i < n;i++){
            string rev = arr[i];
            reverse(rev.begin(), rev.end());
            if(s.find(rev) != s.end()) count++;
            else s.insert(arr[i]);
        
        return ans;
    }
}
*/


/*
class Solution{
public:
    int maximumNumberOfStringPairs(vector<string>& arr){
        int n=  arr.size();
        int count = 0;
        unordered_set<string> s;
        for(int i = 0;i < n;i++){ // O(n)
            s.insert(arr[i]);
        }
        for(int i = 0;i < n;i++){ // O(n)
            string rev = arr[i];
            reverse(rev.begin(), rev.end());
            if(arr[i] == rev) continue;
            if(s.find(rev) != s.end()){ // O(1)
                count++;
                s.erase(arr[i]);
            }
        }
        return count;
    }

}
*/


/*
class Solution{
public:
    int maximumNumberOfStringPairs(vector<string>& arr){
        int n=  arr.size();
        int count = 0;
        // unordered_set<int> s;
        for(int i = 0;i < n-1;i++){
            string rev = arr[i];
            reverse(rev.begin(), rev.end());
            for(int j = i + 1;j < n;j++){
                if(rev == arr[j]) count++
            }
        }
        return count;
    }
}
*/