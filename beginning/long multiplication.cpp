#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        string x, y;
        cin >> x >> y;

        if(x < y){
            swap(x, y);
        }
        bool flag = false;
        for(int i = 0;i < x.size();i++){
            if(x[i] > y[i] && flag == true){
                swap(x[i], y[i]);
            }
            if(x[i] != y[i]){
                flag = true;
            }
        }
        cout << x << endl << y << endl;
    }

    return 0;
}
