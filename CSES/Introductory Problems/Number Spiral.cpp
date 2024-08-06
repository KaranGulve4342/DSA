// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>        
using namespace std;

#define int long long

signed main(){
    int q;
    cin >> q;

    while(q--){
        int x, y;
        cin >> x >> y;

        int maxi = max(x, y);
        int square = (maxi-1)*(maxi-1);

        if(maxi%2 == 0){
            if(y > x){
                cout<<square + x << endl;
            }
            else{
                cout<<(maxi*maxi) - y + 1 << endl;
            }
        }
        else{
            if(y > x){
                cout<<(maxi*maxi) - x + 1 << endl;
            }
            else{
                cout<<square + y << endl;
            }
        }
    }

    return 0;
}