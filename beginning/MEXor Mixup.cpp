// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    int x = 300007;
    
    vector<int> v(x, 0);

    for (int i = 1; i < x; i++) {
        v[i] = v[i - 1] ^ i;
    }

    while(T--){
        int a, b;

        cin >> a >> b;

        if(v[a-1] == b){
            cout<<a<<endl;
        }
        else if(a != (v[a-1] ^ b)){
            cout<<a+1<<endl;
        }
        else{
            cout<<a+2<<endl;
        }
    }

    return 0;
}