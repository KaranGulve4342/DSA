// Codeforces TLE Eleminators 800 Rated

#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n, x;
    cin >> n >> x;


    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    int maxDistance = max(a[0]-0, 2*(x - a[n-1]));
    for(int i = 1;i < n;i++){
        maxDistance = max(maxDistance, a[i] - a[i-1]);
    }
    return maxDistance;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}