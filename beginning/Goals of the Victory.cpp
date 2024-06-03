// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;


int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        vector<int> arr(n-1);
        int sum = 0;
        for(int i = 0;i < n-1;i++){
            cin >> arr[i];
            sum += arr[i];
        }

        cout<<0 - sum<<endl;
    }
}