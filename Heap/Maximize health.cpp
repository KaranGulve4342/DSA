// GFG CONTEST 6TH OCTOBER

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    long long maximizeHealth(int n, vector<int> &A, vector<int> &B, int x, int y) {
        // code here
        vector<long long> pa(n+1);
        
        long long sum = 0;
        
        priority_queue<int, vector<int>, greater<int>> pq;
        
        for(int i = 0;i < n;i++){
            if(A[i] >= 0){
                pq.push(A[i]);
                sum += A[i];
                
                if(pq.size() > x){
                    sum -= pq.top();
                    pq.pop();
                }
            }
            
            pa[i+1] = sum;
        }
        
        while(!pq.empty()){
            pq.pop();
        }
        
        sum = 0;
        
        long long maxi = pa[n];
        
        for(int i = n-1;i >= 0;i--){
            if(B[i] >= 0){
                pq.push(B[i]);
                
                sum += B[i];
                
                if(pq.size() > y){
                    sum -= pq.top();
                    pq.pop();
                }
                
            }
            maxi = max(maxi, pa[i] + sum);
        }
        
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> A(n);
        Array::input(A, n);

        vector<int> B(n);
        Array::input(B, n);

        int x;
        scanf("%d", &x);

        int y;
        scanf("%d", &y);

        Solution obj;
        long long res = obj.maximizeHealth(n, A, B, x, y);

        cout << res << endl;
    }
}

// } Driver Code Ends