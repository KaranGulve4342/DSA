// EVERY PROBLE IS SOLVABLE

#include<bits/stdc++.h>
using namespace std;

#define int long long

int solve(){
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> v;

    int ans = 0;

    for(int i = 0;i < n;i++){
        if(s[i] == '('){
            v.push_back(i);
        }
        else if(s[i] == ')'){
            ans += i - v.back();
            v.pop_back();
        }
        else{
            if(v.size() == 0){
                v.push_back(i);
            }
            else{
                ans += i - v.back();
                v.pop_back();
            }
        }
    }

    return ans;
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}