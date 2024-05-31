// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int solve(){
    int T;
    cin >> T;
    int ans = 0;
    while(T--){
        string str;
        cin >> str;
        if(str.find('++') != ::std::string::npos){
            ans++;
        } else {
            ans--;
        }
    }
    return ans;
}

int main(){
    cout<<solve()<<endl;
    return 0;
}