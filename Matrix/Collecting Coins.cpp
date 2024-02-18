// GFG CONTEST 18 FEB 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int collectingCoins(int N, vector<vector<int>> &Coins) {
        // code here
        int ans = 0;
        int i, j;
        
        vector<int> row, col, sum, diff;
        
        for(i = 0;i < N;i++){
            row.push_back(Coins[i][0]);
            col.push_back(Coins[i][1]);
            sum.push_back(Coins[i][0] + Coins[i][1]);
            diff.push_back(Coins[i][0] - Coins[i][1]);
        }
        
        sort(row.begin(), row.end());
        sort(col.begin(), col.end());
        sort(sum.begin(), sum.end());
        sort(diff.begin(), diff.end());
        
        for(i = 0;i < N;){
            j = i;
            while(i < N && row[i] == row[j]){
                i++;
            }
            ans = max(ans, i-j);
        }
        for(i = 0;i < N;){
            j = i;
            while(i < N && col[i] == col[j]){
                i++;
            }
            ans = max(ans, i-j);
        }
        for(i = 0;i < N;){
            j = i;
            while(i < N && sum[i] == sum[j]){
                i++;
            }
            ans = max(ans, i-j);
        }
        for(i = 0;i < N;){
            j = i;
            while(i < N && diff[i] == diff[j]){
                i++;
            }
            ans = max(ans, i-j);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int N;
        scanf("%d",&N);
        
        
        vector<vector<int>> Coins(N, vector<int>(2));
        Matrix::input(Coins,N,2);
        
        Solution obj;
        int res = obj.collectingCoins(N, Coins);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends