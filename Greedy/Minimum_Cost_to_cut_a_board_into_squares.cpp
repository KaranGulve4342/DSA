/*
A board of length M and width N is given. The task is to break this board into M * N squares such that cost of breaking is minimum. The cutting cost for each edge will be given for the board in two arrays X[] and Y[]. In short, you need to choose such a sequence of cutting such that cost is minimized. Return the minimized cost.
*/

#include<iostream>
#include<vector>
#define ll long long int
using namespace std;

bool cmp(int x, int y){
    return x > y;
}

ll minCostToBreakGrid(int n, int m, vector<ll> &vertical, vector<ll> &horizontal){
    sort(vertical.begin(), vertical.end(), cmp);
    sort(horizontal.begin(), horizontal.end(), cmp);
    int hz = 1;
    int vr = 1;
    int h = 0;
    int v = 0;
    ll ans = 0;

    while(h < horizontal.size() && v < vertical.size()){
        if(vertical[v] > horizontal[h]){
            ans += vertical[v] * vr;
            hz++;
            v++;
        }
        else{
            ans += horizontal[h]*hz;
            vr++;
            h++;
        }
    }
    while(h < horizontal.size()){
        ans += horizontal[h]*hz;
        vr++;
        h++;
    }
    while(v < vertical.size()){
        ans += vertical[v]*vr;
        hz++;
        v++;
    }
    return ans;
}