// CODEFORCES CONYTEST KARAN

#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll karan() {

    ll maxi = 0;

    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    for (ll i = 1; i <= a; i++) {
        for (ll j = 1; j <= b; j++) {

            if (d % (i * j) == 0) {

                ll quotient = d / (i * j);

                if (quotient <= c) {

                    ll val = (a - i + 1) * (b - j + 1);
                    val = val * (c - quotient + 1);

                    maxi = max(maxi, val);

                }
            }
        }
    }

    return maxi;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cout<<karan()<<endl;
    }

    return 0;
}
