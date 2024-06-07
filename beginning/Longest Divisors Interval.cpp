// CODEFORCES 900 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        long long n;
        cin >> n;

        long long ans;
        for(int i = 1;;i++){
            if(n%i != 0){
                ans = i-1;
                break;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}