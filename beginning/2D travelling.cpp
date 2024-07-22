// CODEFORCES 1100 RATED

#include <bits/stdc++.h>
using namespace std;

long long solve(){
    long long n, k, a, b;
    long long price;
    long long pricea_major = LLONG_MAX/2;
    long long priceb_major = LLONG_MAX/2;

    cin >> n >> k >> a >> b;

    vector<long long> x(n+1);
    vector<long long> y(n+1);

    for(int i = 1; i <= n; i++){
        cin >> x[i] >> y[i];
    }

    price = abs(x[a] - x[b]) + abs(y[a] - y[b]);

    for(long long maj = 1;maj <= k;maj++){
        pricea_major = min(pricea_major, abs(x[maj] - x[a]) + abs(y[maj] - y[a]));
        priceb_major = min(priceb_major, abs(x[maj] - x[b]) + abs(y[maj] - y[b]));
    }

    return min(price, pricea_major + priceb_major);
}


int main(){
    long long T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    
    return 0;
}