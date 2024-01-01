/*
class Solution{
public:
    vector<int> candyStore(int candies[], int N, int K){
        sort(candies, candies + N); // sorting an array

        int mini = 0;
        int buy = 0;
        int free = N-1;

        while(buy <= free){
            mini = mini + candies[buy];
            buy++;
            free = free-K;
        }

        int maxi = 0;
        buy = N-1;
        free = 0;

        while(free <= buy){
            maxi = maxi + candies[buy];
            buy--;
            free = free + K;
        }
        vector<int> ans;
        ans.push_back(mini);
        ans.push_back(maxi);
        return ans;
    }
}
*/
/*
class Solution{
public:
    vector<int> candyStore(int candies[], int N, int K){
        sort(candies, candies+N);

        int mini = 0;
        int buy = 0;
        int free = N-1;

        while(buy <= free){
            mini = mini + candies[buy];
            buy++;
            free = free - K;
        }

        int maxi = 0;
        buy = N-1;
        free = 0;

        while(free <= buy){
            maxi = maxi + candies[buy];
            buy--;
            free = free + K;
        }
        vector<int> ans;
        vector.push_back(mini);
        vector.push_back(maxi);
        return ans;
    }
}
*/