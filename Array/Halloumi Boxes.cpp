// Codeforces TLE Eleminators 800 Rated

#include<bits/stdc++.h>
using namespace std;

string solve(){
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    vector<int> sorted = a;
    sort(sorted.begin(), sorted.end());

    if(k > 1) return "YES";
    else{
        if(sorted == a) return "YES";
        else return "NO";
    }
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}
