// CODEFORCES 1100 RATED

#include <bits/stdc++.h>
using namespace std;

string solve(){
    int n, k;
    cin >> n >> k;

    vector<vector<int>>arr(n+1, vector<int>(n+1, 0));

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            cin >> arr[i][j];
        }
    }

    int sum = 0;

    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++){
            if(arr[i][j] != arr[n-i+1][n-j+1]){
                sum++;
            }
        }
    }

    sum /= 2;
    if(sum > k){
        return "NO";
    }

    k -= sum;

    if(n&1){
        return "YES";
    }
    else if(k&1){
        return "NO";
    }
    else{
        return "YES";
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
