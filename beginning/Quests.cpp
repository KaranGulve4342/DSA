// CODEFORCES 1100 RATED

#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n, k;
    cin >> n >> k;
    int ans = INT_MIN;

    vector<int> a(n);
    vector<int> b(n);

    vector<int> suma(n);
    vector<int> maxb(n);

    cin >> a[0];
    suma[0] = a[0];

    for(int i = 1;i < n;i++){
        cin >> a[i];
        suma[i] = suma[i - 1] + a[i];
    }
    cin >> b[0];
    maxb[0] = b[0];

    for(int i = 1;i < n;i++){
        cin >> b[i];
        maxb[i] = max(maxb[i - 1], b[i]);
    }

    k--;

    for(int i = 0;i < n;i++){
        ans = max(ans, suma[i] + (k-i)*maxb[i]);
        if(i == k){
            break;
        }
    }
    return ans;

}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}