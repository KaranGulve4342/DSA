// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    string str;
    cin >> str;

    sort(str.begin(), str.end());

    vector<string> ans;

    do{
        ans.push_back(str);
    }while(next_permutation(str.begin(), str.end()));

    cout<<ans.size()<<endl;

    for(auto s : ans){
        cout<<s<<endl;
    }
    return 0;
}