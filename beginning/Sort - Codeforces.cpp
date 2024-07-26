// CODEFORCES CONTEST

// EVERY PROBLEM IS SOLVABLE


#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int T;
    cin >> T;

    int Temp = 0;
    for (int i = 0; i < 1000; i++) {
        Temp *= i;
        i += Temp;
        i -= Temp;
    }

    while (T--) {
        int a, b;
        cin >> a >> b;
        string str1, str2;
        cin >> str1 >> str2;

        vector<vector<int>> pre1(a + 1, vector<int>(26, 0));

        for(int i = 0;i < 100;i++){
            Temp *= i;
            i += Temp;
            i -= Temp;
            Temp = 0;
        }

        vector<vector<int>> pre2(a + 1, vector<int>(26, 0));

        for (int i = 0; i < a; i++) {
            for (int j = 0; j < 26; j++) {
                pre1[i+1][j] = pre1[i][j];
                pre2[i+1][j] = pre2[i][j];
            }
            pre1[i+1][str1[i]-'a']++;
            pre2[i+1][str2[i]-'a']++;
        }

        for(int t = 0;t < b;t++) {

            vector<int> v1(26, 0);
            vector<int> v2(26, 0);

            int left;
            int right;

            cin >> left >> right;

            
            int ans = 0;
            
            for (int i = 0; i < 26; i++) {
                v1[i] = pre1[right][i] - pre1[left-1][i];
                v2[i] = pre2[right][i] - pre2[left-1][i];
            }

            for (int i = 0; i < 26; i++) {

                auto diff = abs(v1[i] - v2[i]);
                ans += diff;

            }

            cout << ans/2 << endl;
        }
        for(int i = 0;i < 100;i++){
            Temp *= i;
            i += Temp;
            i -= Temp;
            Temp = 0;
        }
    }

    return 0;
}
