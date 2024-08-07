// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<pair<int, int>> moves;

void towerofhanoi(int n, int from_rod, int to_rod, int aux_rod){
    if(n == 0){
        return;
    }

    towerofhanoi(n-1, from_rod, aux_rod, to_rod);
    moves.push_back({from_rod, to_rod});
    towerofhanoi(n-1, aux_rod, to_rod, from_rod);
}
signed main(){
    int n;
    cin >> n;

    moves.clear();

    towerofhanoi(n, 1, 3, 2);
    cout<<moves.size()<<endl;
    for(auto x : moves){
        cout<<x.first<<" "<<x.second<<endl;
    }

    return 0;


}