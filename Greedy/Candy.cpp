// GFG

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int N, vector<int> &ratings) {
        vector<int> candies(N, 1); // Initially assign 1 candy to each child
    
        // Traverse from left to right, checking if the next child has a higher rating
        for (int i = 1; i < N; ++i) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1; // Give one more candy than the previous child
            }
        }
    
        // Traverse from right to left, ensuring higher rating children get more candies
        for (int i = N - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
    
        // Calculate the total candies needed
        long long totalCandies = 0;
        for (int candy : candies) {
            totalCandies += candy;
        }
    
        return totalCandies;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends