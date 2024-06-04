// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

string solve(){
    int n;
    cin >> n;
    int sum = 0;

    while(n--){
        int x;
        cin >> x;
        sum += x;
    }

    return sum%2 ? "NO" : "YES";
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}