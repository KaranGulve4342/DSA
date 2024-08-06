// EVERY PROBLEM IS SOLVABLE

#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n, q;
    cin >> n >> q;

    unordered_map<int, int> umap;
    vector<int> arr(n);

    for(int i = 0;i < n;i++){
        cin >> arr[i];
        if(umap[arr[i]] == 0){
            umap[arr[i]] = i + 1;
        }
    }

    while(q--){
        int t;
        cin >> t;

        int ans = umap[t];
        cout<<ans<<" ";
        umap.erase(t);

        for(auto x : umap){
            if(x.second < ans){
                umap[x.first] = x.second + 1;
            }
        }

        umap[t] = 1;
    }

    cout<<endl;
    return 0;


}