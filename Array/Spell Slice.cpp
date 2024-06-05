#include<bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    
    int maxi = 0;

    vector<pair<int, int>> v(n);
    
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second; 
    }

    for (int i = 0; i < n; j++) {
        for (int j = i + 1; j < n; j++) {
            int temp1 = v[i].first * v[j].second;
            int temp2 = v[i].second * v[j].first;

            int temp = temp1 + temp2;
            if (temp > maxi) {
                maxi = temp;
            }
        }
    }

    cout << maxi << endl; 
}
int main() {
    int T;
    cin >> T;
    
    while (T--) {
        solve();
    }
    return 0;
}
