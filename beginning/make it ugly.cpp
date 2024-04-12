// Codeforces

#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    unordered_map<int, int> umap;
    for(int i = 0;i < n;i++){
        umap[a[i]]++;
    }

    if(umap.size() == 1){
        return -1;
    }

    int x = a[0];
    int ix = 0;
    int ans = n;
    for(int i = 0;i < n;i++){
        if(a[i] == a[0]){
            ix++;
        }
        else{
            ans = min(ans, ix);
            ix = 0;
        }
    }
    ans = min(ans, ix);
    return ans;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cout<<solve()<<endl;
    }
}