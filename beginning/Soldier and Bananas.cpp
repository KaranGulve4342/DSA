// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int main(){
    int k, n, w;
    cin >> k >> n >> w;

    int amount = 0;
    int idx = 1;
    while(w--){
        amount += k*idx;
        idx++;
    }

    if(amount < n) cout << 0 << endl;
    else cout << amount - n << endl;
    return 0;
}