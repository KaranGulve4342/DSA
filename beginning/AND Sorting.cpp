// CODEFORCES 1100 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        int ans = (1 << 20) - 1;

        for(int i = 0;i < n;i++){
            int x;
            cin >> x;

            if(x != i){
                ans &= x;
            }
        }

        cout<<ans<<endl;
    }
    return 0;
}