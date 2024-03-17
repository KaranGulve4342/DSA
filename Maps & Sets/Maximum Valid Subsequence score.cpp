/*
Editorial
Brute Force Approach
Intuition
The main idea is to iterate through the array and consider each element as a potential starting point of a subsequence. For each starting point, we iterate through the subsequent elements to check if they form a valid subsequence according to the given condition.

The main condition is this:
=> arr[b[i]]-arr[b[i-1]]=b[i]-b[i-1]
=> arr[i] - arr[j] = i - j
=> arr[i] - i = arr[j] - j
From the above equation, we can see that if arr[i]-i is equal then this satisfies the main condition present in the problem, Hence we just have to sum up that arr[i] which satisfies the above condition, and return the maximum we get.

Implementation
Initialize a variable maxScore to store the maximum score found.
Iterate through each element arr[i] of the array.
For each arr[i], start with the current score arr[i].
Iterate through the array starting from the next index j = i + 1.
For each arr[j], if the condition arr[j] - j = arr[i] - i is satisfied, add arr[j] to the current score.
Update maxScore with the maximum value between the current score and maxScore.
Return maxScore as the maximum score of a valid subsequence.


class Solution {
  public:
    int maxScoreSubseq(int n, vector<int> &arr) {
        // code here
        int maxScore = 0;
        for (int i = 0; i < n; i++) {
            if(arr[i] < 0) continue;
            int currentScore = arr[i];
            for (int j = i + 1; j < n; j++) {
                if((arr[j]-j) == (arr[i]-i)) {
                    currentScore += arr[j];
                }
            }
            maxScore = max(maxScore, currentScore);
        }
        return maxScore;
    }
};

Complexity
Time Complexity: O(n^2), where n is the size of the array arr. This is because we iterate through each element of the array and, for each element, potentially iterate through the remaining elements to check for valid subsequences.
Space Complexity: O(1) as the algorithm uses only a constant amount of extra space regardless of the input size. We only store a few variables to keep track of the maximum score and the current score.
Expected Approach
Intuition
The main condition is this:
=> arr[b[i]]-arr[b[i-1]]=b[i]-b[i-1]
=> arr[i] - arr[j] = i - j
=> arr[i] - i = arr[j] - j
From the above equation, we can see that if arr[i]-i is equal then this satisfies the main condition present in the problem, Hence we just have to sum up that arr[i] which satisfies the above condition, and return the maximum we get.

Here instead of using nested loop the main idea is to constructs a map that stores the sum of values of elements having the same difference between their value and index. It then iterates through the array, updating this map and tracking the maximum element. Finally, it returns the maximum of the maximum element found in the array and the maximum value in the map.

Implementation
Initialize an unordered map mp to store the sum of values of elements with the same difference between their value and index.
Also, initialize a variable ma to track the maximum element in the array.
Traverse through each element of the array.
For each non-negative element arr[i], update the map by adding arr[i] to the value corresponding to the key (arr[i] - i).
Update the maximum element ma encountered in the array.
Initialize a variable ele to track the maximum sum obtained from the map.
Iterate through the map and update ele with the maximum sum found.
Return the maximum of ele and ma, which represents the maximum score achievable by either selecting a subsequence from the map or selecting the maximum element from the array.
Example
Input:
n = 5
arr = {1, 5, 3, 7, 8}

Output: 20

Explanation:
The subsequence of indices b can be selected as {1, 3, 4}.
Now, b is a valid subsequence because:

arr[3]-arr[1] = 7-5 = 2 = 3-1
arr[4]-arr[3] = 8-7 = 1 = 4-3
Score of b = 5+7+8 = 20.

Code
class Solution {
  public:
    int maxScoreSubseq(int n, vector<int> &arr) {
        unordered_map<int,int>mp;
        int ma=INT_MIN;
        for (int i=0;i<n;i++){
            if (arr[i]>=0)mp[arr[i]-i]+=arr[i];
            ma=max(ma,arr[i]);
        }
        int ele=INT_MIN;
        for (auto j:mp) ele=max(ele,j.second);
        return max(ele,ma);
    }
};
Complexity
Time Complexity: O(n),
The algorithm iterates through the array once, resulting in O(n) time complexity.
Constructing the map and finding the maximum sum from it takes O(n) time.
Overall, the time complexity is O(n).
Space Complexity: O(n),
The space complexity is O(n) due to the storage of the map mp.
Additional space for variables is constant and negligible.
Therefore, the space complexity is O(n).

/contest/gfg-weekly-codin
*/

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int maxScoreSubseq(int n, vector<int> &arr) {
        unordered_map<int, int> mp;
        
        int mx = INT_MIN;
        
        for(int i = 0;i < n;i++){
            mx = max(mx, arr[i]);
            if(arr[i] >= 0){
                mp[arr[i] - i] += arr[i];
            }
        }
        
        int mxSum = INT_MIN;
        for(auto x : mp){
            if(x.second > mxSum){
                mxSum = x.second;
            }
        }
        
        return max(mx, mxSum);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.maxScoreSubseq(n, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends