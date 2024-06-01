// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int minCapacity = 0;
    int count = 0;
    while(n--){
        int a, b;
        cin >> a >> b;

        count -= a;
        count += b;
        minCapacity = max(minCapacity, count);
    }

    cout<<minCapacity<<endl;
    return 0;
}