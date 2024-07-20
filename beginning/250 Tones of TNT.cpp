// CODEFORCES 1100 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long T;
    cin >> T;

    while(T--){
        long long n;
        cin >> n;

        long long it;

        long long ans = 0;

        vector<long long> pre;
        long long sum = 0;
        pre.push_back(0);

        for(long long i = 0;i < n;i++){
            cin >> it;
            sum += it;
            pre.push_back(sum);
        }

        for(long long i = 1;i <= n;i++){
            vector<long long> v;
            if(n%i == 0){
                for(long long j = i;j <= n;j += i){
                    v.push_back(pre[j] - pre[j - i]);
                }
                sort(v.begin(), v.end());
                ans = max(ans, v[(long long)v.size() - 1] - v[0]);
            }
        }
        cout << ans << endl;
    }
}