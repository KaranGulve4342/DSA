// CODEFORCES

// every problem is solvable

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n);

        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }

        if(n == 2 && arr[1] != arr[0] + 1){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    return 0;
}