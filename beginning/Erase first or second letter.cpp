// CODEFORCES 1100 RATED

#include <bits/stdc++.h>   
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;
        string str;
        cin >> str;
        unordered_set<char> st;

        long long ans = 0;

        for(int i = 0;i < n;i++){
            st.insert(str[i]);
            ans += (long long)st.size();
        }
        cout << ans << endl;
    }
    return 0;
}