// LEETCODE 3044

class Solution {
public:
    bool isPrime(int n){
        if(n < 2) return false;
        if(n == 2) return true;

        for(int i = 2;i * i <= n;i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int x[8] = {0, 0, 1, 1, 1, -1, -1, -1};
        int y[8] = {1, -1, 0, 1, -1, 0, 1, -1};

        unordered_map<int, int> umap;

        for(int i = 0;i < mat.size();i++){
            for(int j = 0;j < mat[0].size();j++){
                for(int k = 0;k < 8;k++){
                    int num = mat[i][j];
                    umap[num]++;
                    int i1 = i;
                    int j1 = j;

                    while((i1 + x[k] >= 0) && (i1 + x[k] < mat.size()) && (j1 + y[k] >= 0) && (j1 + y[k] < mat[0].size())){
                        num = num * 10 + mat[i1 + x[k]][j1 + y[k]];
                        i1 += x[k];
                        j1 += y[k];

                        umap[num]++;
                    }

                }
            }
        }
        int mx = 0;
        unordered_set<int> st;
        for(auto x : umap){
            if(isPrime(x.first) && x.first > 10){
                mx = max(mx, x.second);
            }
        }

        int ans = -1;
        for(auto x : umap){
            if(isPrime(x.first) && (x.first > 10) && x.second == mx){
                ans = max(ans, x.first);
            }
        }

        return ans;
    }
};