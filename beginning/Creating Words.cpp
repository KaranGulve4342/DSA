#include<bits/stdc++.h>
using namespace std;

vector<string> solve(int t, const vector<pair<string, string>> &test) {
    vector<string> ans;
    for (auto x : test) {
        string a = x.first;
        string b = x.second;
        swap(a[0], b[0]);
        ans.push_back(a + " " + b);
    }
    return ans;
}

int main() {
    int T;
    cin >> T;
    vector<pair<string, string>> test;
    
    while (T--) {
        string first, second;
        cin >> first >> second;
        test.push_back({first, second});
    }
    
    vector<string> ans = solve(test.size(), test);

    for (auto &a : ans) {
        cout << a << endl;
    }
    
    return 0;
}
