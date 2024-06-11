
// CODEFORCES CONTEST KARAN

#include<bits/stdc++.h>
using namespace std;


long long solve() {

    long long n;
    cin >> n;
    
    vector<long long> arr(n);
    
    long long curr = 0;
    
    unordered_set<long long> uset; 
    
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0;i < n; i++) {

        uset.insert(arr[i]);
        curr += arr[i];

        if (!(curr&1)) {
            long long temp = curr / 2;
            if (uset.count(temp)) {
                ans++;
            }
        }
    }
    return ans;
}


int main() {
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}
