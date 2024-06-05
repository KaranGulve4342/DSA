// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int solve(){
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((b>d) || (c-a)>(d-b)) return -1;
    else return 2*(d-b)+a-c;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}