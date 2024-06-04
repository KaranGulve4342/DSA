// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

string solve(){
    int a, b, c;
    cin >> a >> b >> c;

    if(a + c%2 > b){
        return "First";
    }
    return "Second";
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}