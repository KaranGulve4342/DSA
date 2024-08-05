// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

bool binary_search(vector<int>& arr, int target){
    int lo = 0, hi = arr.size() - 1;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(arr[mid] == target){
            return true;
        }
        else if(arr[mid] < target){
            lo = mid + 1;
        }
        else{
            hi = mid - 1;
        }
    }
    return false;
}

string solve(){
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    sort(arr.begin(), arr.end());

    for(int i = 0;i < n;i++){
        if(binary_search(arr.begin(), arr.end(), arr[i] + k)){
            return "YES";
        }
    }

    // unordered_set<int> s;
    // for(int i = 0;i < n;i++){
    //     if(s.find(arr[i] - k) != s.end() || s.find(arr[i] + k) != s.end()){
    //         return "YES";
    //     }
    //     s.insert(arr[i]);
    // }
    return "NO";
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}