// Codeforces

#include <bits/stdc++.h>
using namespace std;

string solve(){
    int n,m,k;
    cin >> n >> m >> k;

    // if(m == k){
    //     return "NO";
    // }
    // else{
        
    // }
    if(n - (n/m + (n%m != 0)) <= k) return "NO";
    else return "YES";


}

int main(){
    int T;
    cin >> T;
    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}