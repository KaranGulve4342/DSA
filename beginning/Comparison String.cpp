// CODEFORCES 900 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin>>n;
    
        string s;
        cin>>s;
        
        int maxi = 1, cnt=1;
        for(int i=1; i<n; i++){
            if(s[i] == s[i-1])
                cnt++;
            else
                cnt = 1;
            maxi = max(maxi, cnt);
        }
    
        cout<<maxi+1<<endl;
    }

    return 0;
}