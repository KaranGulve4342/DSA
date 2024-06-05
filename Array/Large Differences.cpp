#include<bits/stdc++.h>
using namespace std;

int solve() {

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    int sum = 0;
    int maxi = 0;

    for (int j = 0; j < n; ++j) {
        cin >> a[j];
    }

    for (int i = 0; i < n - 1; ++i) {
        sum += abs(a[i] - a[i + 1]);
    }

    maxi = sum;
    
    for (int i = 0; i < n; ++i) {
        if (i > 0) {
            
            int temp = sum;
            temp -= abs(a[i] - a[i - 1]);
            temp += abs(1 - a[i - 1]);
            if (i < n - 1) {
                temp += abs(1 - a[i + 1]);
                temp -= abs(a[i] - a[i + 1]);
            }
            maxi = max(maxi, temp);
        }
    }

    for(int i = 0;i < n;i++){
        if (i < n - 1) {
            int temp = sum;
            temp -= abs(a[i] - a[i + 1]);
            temp +=  abs(k - a[i + 1]);
            if (i > 0) {
                temp += abs(k - a[i - 1]);
                temp -= abs(a[i] - a[i - 1]);
            }
            maxi = max(maxi, temp);
        }
    }
    
    return maxi;
}

int main() {
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}
