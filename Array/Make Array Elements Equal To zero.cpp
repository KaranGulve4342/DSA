// LEETCODE 3354

class Solution {
public:
    bool check(vector<int>& arr){
        for(auto a : arr){
            if(a!=0) return false;
        }
        return true;
    }
    bool solve(vector<int> arr, int start, int direction){
        int n = arr.size();
        int idx = start;

        while(idx >= 0 && idx < n){
            if(arr[idx] == 0){
                idx += direction;
            }
            else{
                direction *= -1;
                arr[idx] -= 1;
                idx += direction;
            }
        }

        bool ans = check(arr);
        return ans;
    }
    int countValidSelections(vector<int>& arr) {
        int n = arr.size();

        int ans = 0;

        for(int i = 0;i < n;i++){
            if(arr[i] == 0){
                if(solve(arr, i, 1)){
                    ans++;
                }
                if(solve(arr, i, -1)){
                    ans++;
                }
            }
        }

        return ans;
    }
};