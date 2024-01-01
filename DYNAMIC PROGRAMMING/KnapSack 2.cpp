#include<iostream>
#include<vector>
#include<climits>
#define ll long long int;
using namespace std;

vector<vector<ll> >dp(105, vector<ll> (100005, -1));

ll f(vector<int> &wts, vector<int> &val, int idx, int tv){
    if(tv == 0) return 0;
    if(idx == wts.size()) return INT_MAX;
    if(dp[idx][tv] != -1) return dp[idx][tv];
    ll ans = INT_MAX;
    // not pick
    ans = min(ans, f(wts, val, idx+1, tv));
    // pick
    if(val[idx] <= tv) {
        ans = min(ans, wts[idx] + f(wts, val, idx+1, tv-val[idx]));
    }

    return dp[idx][tv] = ans;
}

int main(){
    int n, w;
    vector<int> wts, val;
    for(int i = 0;i < n;i++){
        int w, n;
        cin>>w>>v;
        wts.push_back(w);
        val.push_back(v);
    }
    int result = -1;
    for(int i = 0;i <= n*1000;i++){
        if(f(wts, val, 0, i) <= W){
            result = i;
        }
    }
    cout<<result;
    return 0;
}