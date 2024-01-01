#include<bits/stdc++.h>
using namespace std;

bool isPerfectSquare(int num){
    int lo = 0;
    int hi = num - 1;
    

    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if((long long)mid*mid == num){
            return true;
        }
        else if((long long)mid*mid < num){
            lo = mid + 1;
        }
        else hi = mid - 1;
    }
    return false;
}
int main(){
    cout<<isPerfectSquare(49)<<endl;
    cout<<isPerfectSquare(50)<<endl;
}