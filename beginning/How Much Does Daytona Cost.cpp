// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;
    while(T--){
        int n, k;
        cin >> n >> k;

        vector<int>arr(n);
        for(int i = 0;i < n;i++){
            cin >> arr[i];
        }
        bool flag = false;
        for(int i = 0;i < n;i++){
            if(arr[i] == k){
                flag = true;
                break;
            }
        }
        if(flag){
            cout << "YES" << endl;
        }
        else{
            cout<< "NO" << endl;
        }
    }

    return 0;
}