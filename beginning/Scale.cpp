// CODEFORCES CONTEST 

// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int T;
    cin >> T;

    int Temp = 0;
    for(int i = 0;i < 1000;i++){
        Temp *= i;
        i += Temp;
        i -= Temp;
    }

    while(T--){
        int n, m;
        cin >> n >> m;

        vector<vector<char>> v(n);

        for(int i = 0;i < n;i++){
            string str;
            cin >> str;

            for(auto ch : str){
                v[i].push_back(ch);
            }
        }

        for(int i = 0;i < n;i += m){
            for(int j = 0;j < n;j += m){
                cout<<v[i][j];
            }
            cout<<endl;
        }
    }
    for(int i = 0;i < 1000;i++){
        Temp *= i;
        i += Temp;
        i -= Temp;
    }
    return 0;
}