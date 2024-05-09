// CODESHEF STARTERS 133 8TH MAY

#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    vector<int> bpos;
    vector<vector<int>> prefix(n, vector<int>(3, 0));

    for (int i = 0; i < n; ++i) {
        
        prefix[i][s[i] - 'a'] += 1;

        if (s[i] == 'b') {
            bpos.push_back(i);
        }
        if (i > 0) {
            prefix[i][0] += prefix[i - 1][0];
            prefix[i][1] += prefix[i - 1][1];
            prefix[i][2] += prefix[i - 1][2];
        }
    }   

    if (bpos.empty()) {
        return 0;
    }

    if (bpos.size() == 1) {
        return min(prefix[bpos[0]][0], prefix[n - 1][2] - prefix[bpos[0]][2]);
    }

    int ans = n;
    for (int i = 0; i < (int) bpos.size() - 1; ++i) {
        auto l = bpos[i];
        auto r = bpos[i + 1];
        ans = min(ans, prefix[l][0] + prefix[n - 1][2] - prefix[r][2]);
    }

    ans = min(ans, prefix[n - 1][2] - prefix[bpos[0]][2]);
    ans = min(ans, prefix[bpos.back()][0]);

    return ans;
} 

int main() {
	// your code goes here
	int T;
	cin >> T;
	while(T--){
	    cout<<solve()<<endl;
	}
	return 0;

}
