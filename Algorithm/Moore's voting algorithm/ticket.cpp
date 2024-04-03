#include<bits/stdc++.h>
using namespace std;

vector<int> ans;

void solve(){
    int n;
    vector<int> temp;
    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        temp.push_back(x);
    }
    
    while(temp.size() != 0){
        if(temp[0] >= 0){
            ans.push_back(temp.size());
            for(int t = 0;t < temp.size();t++){
                temp[t] -= 1;
                if(temp[t] < 0){
                    temp.erase(temp.begin() + t);
                }
            }
        }
    }
    
}

int main(){
    int T;
    cin >> T;
    while(T--){
        solve();
        for(int i = 0;i < ans.size();i++){
            cout<<ans[i] << " ";
        }
    }
    return 0;
}