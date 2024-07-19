// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int> a(n);
        for(int i = 0; i < n; i++){
            cin >> a[i];
        }

        sort(a.begin(), a.end(), greater<int>());

        for(int i = 0; i < n; i++){
            cout << a[i] << " ";
        }
    }
    return 0;
}