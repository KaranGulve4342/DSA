// GFG CONTEST 14TH JAN 2024

class Solution{
    int candyShop(int n, vector<int> &candies){
        int f = 0, curr = 0, c[1001], ans = 100000000, sum = 0;

        for(int i = 0;i <= 1000;i++){
            c[i] = 0;
        }

        for(int i = 0;i < n;i++){
            c[candies[i]]++;
        }

        for(int i = 0;i <= 1000;i++){
            if(c[i] > 0){
                f++;
            }
        }

        for(int i = 0;i <= 1000;i++){
            c[i] = 0;
        }

        int i = 0;
        int j = 0;

        for(int j = 0;j < n;j++){
            c[candies[j]]++;
            sum = sum + candies[j];

            if(c[candies[j]] == 1){
                curr++;
            }

            while(curr == f){
                ans = min(ans, sum);
                c[candies[i]]--;
                if(c[candies[i]] == 0){
                    curr--;
                }
                sum = sum - candies[i];
                i++;
            }
        }
        return sum;
    }
}