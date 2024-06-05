// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    int sum = 0;
    int count = 0;
    for(int i = 0;i < n;i++){
        cin >> a[i];
        sum += a[i];
        if(a[i] == -1){
            count++;
        }
    }
    int ans = 0;
    if(sum >= 0 && count % 2 == 0){
        return 0;
    }
    
    if(count % 2 != 0){
        count -= 1;
        ans++;
    }   

    while(count > n - count){
        count -= 2;
        ans += 2;
    }

    return ans;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}