// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

string solve(){
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int flag = 0;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++){
            if(__gcd(a[i],a[j])<=2) flag=1;
        }
    }

    if(flag) return "YES";
    return "NO";
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}