// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin >> n;
    int len = 0;
    int maxLen = 0;

    for(int i = 0;i < n;i++){
        int x;
        cin >> x;
        if(x == 0){
            len++;
            maxLen = max(maxLen, len);
        }
        else{
            len = 0;
        }
    }

    return maxLen;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
}