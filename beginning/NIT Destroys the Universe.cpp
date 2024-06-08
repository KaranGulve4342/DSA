// CODEFORCES 900 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        int ans = 0;
        int prev;

        cin >> n;
        cin >> prev;

        if(prev != 0) ans++;
        for(int i = 1;i < n;i++){
            int num;
            cin >> num;
            if(num != 0){
                if(prev == 0){
                    ans++;
                }
            }
            prev = num;
        }

        cout<<min(2, ans)<<endl;
    
    }
    return 0;
}
