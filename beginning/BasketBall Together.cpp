// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    int players = 0;
    int i = 0;
    int wins = 0;

    while(i < n && players <= n){
        int x = ceil((d + 1)/(a[i] * 1.0));
        players = players + x;
        if(players <= n){
            wins++;
        }
        i++;
    }
    cout<<wins<<endl;

    return 0;
}