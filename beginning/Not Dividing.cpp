// CODEFORCES 900 RATED

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        if(arr[i] == 1) {
            arr[i] += 1;
        }
    }

    for(int i = 1;i < n;i++){
        if(arr[i] % arr[i-1] == 0){
            arr[i] += 1;
        }
    }

    for(int i = 0;i < n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        solve();
    }

    return 0;
}