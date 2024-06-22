// CODEFORCES 900 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long T;
    cin >> T;

    while(T--){
        long long n,k;
        cin>>n>>k;
    
        vector<long long>arr(n*k);
        for(long long i=0; i<arr.size(); i++){
            cin>>arr[i];
        }
    
        long long ans = 0;
        long long i=n*k;
        
        while(k--){
            i = i - (n/2 + 1);
            ans += arr[i];
        }
        cout<<ans<<endl;
    }

    return 0;
}