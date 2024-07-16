// CODEFORCES 1000 RATED

#include <bits/stdc++.h>
using namespace std;

bool isFairNumber(long long n){
    long long temp = n;
    while(temp){
        int digit = temp%10;
        if(digit != 0 && n%digit != 0){
            return false;
        }
        temp /= 10;
    }
    return true;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        long long n;
        cin >> n;

        while(!isFairNumber(n)){
            n++;
        }   
        cout<<n<<endl;
    }
    return 0;
}