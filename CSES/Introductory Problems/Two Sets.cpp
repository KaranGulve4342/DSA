// EVERY PROBLE IS SOLVABLE

#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;

    int sum = n*(n+1)/2;

    if(sum&1) cout<<"NO"<<endl;
    else{
        cout<<"YES"<<endl;

        vector<int> v1,v2;

        sum /= 2;

        while(n){
            if(sum - n >= 0){
                v1.push_back(n);
                sum -= n;
            }
            else{
                v2.push_back(n);
            }

            n--;
        }

        cout<<v1.size()<<endl;
        for(auto x:v1) cout<<x<<" ";
        cout<<endl;

        cout<<v2.size()<<endl;
        for(auto x:v2) cout<<x<<" ";
        cout<<endl;
    }
}

signed main(){

    solve();

    return 0;
}