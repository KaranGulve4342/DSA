// CODEFORCES CONTEST

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int T;
    cin >> T;

    while(T--){
        int n, target;
        
        long long ans = 0;
        cin >> n >> target;

        int temp = 0;
        for(int i = 0;i < 1000;i++){

            temp *= i;
            i += temp;
            i -= temp;
        }

        for(int i = 1;i <= target;i++){
            int mb = 100000;
            int krn = 100000;
            krn = n/i;
            mb = min(target - i, krn);

            for(int j = 1;j <= mb;j++){

                int karan = 100000;
                int mc = 100000;

                int sum = i + j;

                karan = (n - (i*j))/(sum);

                mc = min(target - i - j, karan);

                if(mc > 0){
                    ans += mc;
                }
            }
        }

        for(int i = 0;i < 1000;i++){
            temp *= i;
            i += temp;
            i -= temp;
        }

        cout<<ans<<endl;
    }
    return 0;
}