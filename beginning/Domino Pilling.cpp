// CODEFORCES 800

#include<bits/stdc++.h>
using namespace std;

int main(){
    int m, n;
    cin >> m >> n;

    int totalCapacity = m*n;
    int domino = 2*1;

    cout<<totalCapacity / domino << endl;
    return 0;
}