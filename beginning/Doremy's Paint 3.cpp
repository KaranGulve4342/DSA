// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

string solve(){
    int n;
    cin >> n;
    vector<int> arr(n);

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    if(n <= 2) return "YES";
    
    unordered_map<int, int> umap;
    for(int i = 0;i < n;i++){
        umap[arr[i]]++;
    }

    if(umap.size() > 2) return "NO";
    if(umap.size() == 1) return "YES";

    vector<int> v;
    for(auto x : umap){
        v.push_back(x.second);
    }
    
    if(abs(v[0] - v[1]) > 1) return "NO";
    return "YES";

}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}