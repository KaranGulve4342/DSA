// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n, m;
        cin >> n >> m;

        if(n < m){
            cout << "No" << endl;
        }
        else{
            if((n - m) % 2 == 0){
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}