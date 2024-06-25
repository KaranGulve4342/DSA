// codeforces 1000 rated

#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    for(auto x : arr){
        if(x%k == 0){
            return 0;
        }
    }

    if(k == 2 || k == 3 || k == 5){
        int mini = INT_MAX;
        for(auto x : arr){
            mini = min(mini, k*((x+k-1)/k) - x);
        }
        return mini;
    }
    else{
        int mini = INT_MAX;
        for(auto x : arr){
            mini = min(mini, k*((x+k-1)/k) - x);
        }

        vector<int> diff;
        for(auto x : arr){
            diff.push_back(2*((x+1)/2)-x);
        }
        sort(diff.begin(), diff.end());

        return min(mini, diff[0] + diff[1]);
    }
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}