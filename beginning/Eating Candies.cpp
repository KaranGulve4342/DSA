// CODEFORCES 1100 RATED

#include <bits/stdc++.h>
using namespace std;

#define int long long

int solve(){
    int n;
    cin >> n;

    vector<int> weight(n);
    for(int i = 0;i < n;i++){
        cin >> weight[i];
    }

    int left = 0;
    int right = n - 1;

    int maxi = 0;

    int sumAlice = 0;
    int sumBob = 0;

    while(left <= right){
        if(sumAlice < sumBob){
            sumAlice += weight[left++];
        }
        else{
            sumBob += weight[right--];
        }

        if(sumAlice == sumBob){
            maxi = max(maxi, left + (n - right - 1));
        }
    }

    return maxi;
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}