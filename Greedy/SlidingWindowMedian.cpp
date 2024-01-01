#include <bits/stdc++.h>
using namespace std;

double getMedian(priority_queue<int> &left, priority_queue<int, vector<int>, greater<int> > &right, int x, int y){
    int totalSize = x + y;
    if(totalSize%2 != 0){
        // odd
        return right.top();
    }
    else{
        // even
        return (left.top() + right.top())/2.0;
    }
}

bool isBalanced(int x, int y){
    return (x == y) or (x + 1 == y);
}

vector<double> sliding_median(vector<int> &arr, int n, int k){
    priority_queue<int> left;
    priority_queue<int, vector<int>, greater<int> > right;
    right.push(arr[0]);
    int x = 0,y = 0;
    for(int i = 1;i < k;i++){
        int curr = arr[i];
        double med = getMedian(left, right,x,y);
        if(curr < med){
            // go left
            left.push(curr);
            x++;
            if(!isBalanced(x,y)){
                int toberemoved = left.top();
                left.pop();
                right.push(toberemoved);
                x--;
                y++;
            }
        }
        else{
            // go right
            right.push(curr);
            y++;
            if(!isBalanced(x,y)){
                int toberemoved = right.top();
                right.pop();
                left.push(toberemoved);
                y--;
                x++;
            }
        }
    }
    double m = getMedian(left,right,x,y);
    vector<double> result;
    result.push_back(m);
    unordered_map<int, int> mp;

    for(int i = k;i < n;i++){
        int newElementIndex = i;
        int oldElementToBeDeleted = i-k;
        double med =getMedian(left, right, x,y);
        if(arr[newElementIndex] > med){
            // go right
            right.push(arr[newElementIndex]);
            y++;
            if(!isBalanced(x,y)){
                int toberemoved = left.top();
                left.pop();
                right.push(toberemoved);
                x--;
                y++;
            }

        }
        else{
            // go left
            left.push(arr[newElementIndex]);
            x++;
            if(!isBalanced(x, y)){
                int toberemoved = right.top();
                right.pop();
                left.push(toberemoved);
                y--;
                x++;
            }
        }
        mp[arr[oldElementToBeDeleted]] = oldElementToBeDeleted; 
        while(!left.empty() && mp[left.top()]){
            mp.erase(left.top());
            left.pop();
            x--;
            if(!isBalanced(x,y)){
                int toberemoved = right.top();
                right.pop();
                left.push(toberemoved);
                y--;
                x++;
            }
        }
        while(!right.empty() && mp[right.top()]){
            mp.erase(right.top());
            right.pop();
            y--;
            if(!isBalanced(x, y)){
                int toberemoved = left.top();
                left.pop();
                right.push(toberemoved);
                x--;
                y++;
            }
        }
        result.push_back(getMedian(left, right, x, y));
    }

    return result;
}
int main()
{
    // int t = 1;
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin>>arr[i];
    }
    vector<double> ans = sliding_median(arr, n, k);
    for(int i = 0;i < ans.size();i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}