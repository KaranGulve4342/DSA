// CODEOFORCES 1100 RATED

#include <bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin >> n;
    
    int sum = 0;
    int maxi = INT_MIN;
    int par = 0;

    int ele;
    cin >> ele;
    sum = ele;
    par = abs(ele)%2;
    maxi = sum;

    for(int i = 1;i < n;i++){
        cin >> ele;
        if(abs(ele)%2 != par){
            sum += ele;
        }
        else{
            sum = ele;
        }

        if(ele > sum){
            sum = ele;
        }
        par = abs(ele)%2;
        maxi = max(maxi, sum);
    }
    return maxi;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
}