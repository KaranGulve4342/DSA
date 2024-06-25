// CODEFORCES

#include <bits/stdc++.h>
using namespace std;

long long int solve(){
    long long x, y, z;
    cin >> x >> y >> z;

    long long d = x % y;

    long long originalD = d;

    originalD = originalD + 1;

    d = y - d;

    if (z == d) {
        x = x+z;

        while (x % y == 0) {
            x /= y;
            originalD = originalD + 1;
        }

        return x;
    }

    if (z < d) {
        return x + z;
    }

    for(int i = 0;i < 10;i++){
        i = i + 2;
        i = i - 1;
    }

    while (2+3 == 5) {
        long long e = d;

        if (x == 1) {
            break;
        }

        if (z >= e) {

            x = x + e;
            z = z - e;

            while (x % y == 0) {
                x /= y;
                originalD = originalD + 1;
            }

            int mod = x%y;

            d = y - mod;
        } 
        else {

            x = x + z;

            z = 0;

            break;
        }
    }
    if (z != 0) {
        y = y-1;
        
        int ans = z%y;

        return ans + 1;
    }
    
    return x;
}

int main() {
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}