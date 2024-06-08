// CODEFORCES 900 RATED

#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n, b;
    int ans = 0;

    cin >> n;
    for(int i = 1;i <= n;i++){
        cin >> b;
        if(abs(b - i) != 0){
            ans = __gcd(ans, abs(b-i));
        }
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