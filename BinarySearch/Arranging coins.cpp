#include<bits/stdc++.h>
using namespace std;

int arrangeCoins(int n){
    int lo = 1;
    int hi = n;
    int mid = lo + (hi - lo)/2;
    while(lo <= hi){
        mid = lo + (hi - lo)/2;
        int coins = (mid * (mid + 1))/2;

        if(coins == n){
            return (int)mid;
        }
        if(coins < n){
            lo = mid + 1;
        }
        else hi = mid - 1;

    }
    return (int)hi;
}
int main(){
    cout<<arrangeCoins(8);
}