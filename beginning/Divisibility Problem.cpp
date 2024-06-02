// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int a, b;
        cin >> a >> b;

        if(b >= a){
            cout<<b - a<<endl;
            continue;
        }
        else{    
            if(a % b == 0){
                cout<<0<<endl;
                continue;
            }
            else{
                cout<<b - a % b<<endl;
                continue;
            }
        }
    }
    return 0;
}