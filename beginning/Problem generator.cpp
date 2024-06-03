// CODEFORCES CONTEST KARAN

#include<bits/stdc++.h>
using namespace std;

int karan(){
    int n, m;
    string str;
    cin >> n >> m;
    cin >> str;

    int ans = 0;

    vector<int> bit(7, 0);

    for (char c : str) {
        bit[c - 'A']++;
    }

    for (int i = 0; i < 7; ++i) {
        if (bit[i] < m) {
            ans += (m - bit[i]);
        }
    }
    return ans;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        cout<<karan()<<endl;
    }

    return 0;
}
