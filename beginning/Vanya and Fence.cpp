// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n, h;
    cin >> n >> h;
    int ans = 0;
    while(n--){
        int a;
        cin >> a;
        if(a > h){
            ans += 2;
        }
        else{
            ans++;
        }
    }
    return ans;
}

int main(){
    cout<<solve()<<endl;
}