
#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int n;
    cin >> n;

    int total = n*(n + 1)/2;

    int sum = 0;

    while(n>1){
        int x;
        cin >> x;
        sum += x;
        n--;
    }

    cout << total - sum << endl;


    return 0;
}