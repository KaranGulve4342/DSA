#include <bits/stdc++.h>
using namespace std;


bool flag(long long a, long long b, long long c, long long d) {
    long long diff1 = a - b;
    long long diff2 = c - d;

    bool flag1 = (diff1 != 0 && diff2 != 0);
    bool flag2 = !((diff1 > 0 && diff2 < 0) || (diff1 < 0 && diff2 > 0));

    return flag1 && flag2;
}


string solve(){
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    if(flag(a, b, c, d)){
        return "YES";
    }
    return "NO";
}

int main() {
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}