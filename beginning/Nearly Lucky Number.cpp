// CODEFORCES: 110/A - Nearly Lucky Number

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

string solve(){
    long long n;
    cin >> n;
    long long countLuckyDigits = 0;
    
    while(n) {
        if (n%10 == 4 || n%10 == 7) {
            countLuckyDigits++;
        }
        n /= 10;
    }

    if (countLuckyDigits == 4 || countLuckyDigits == 7) {
        return "YES";
    }
    return "NO";
}

int main(){
    cout<<solve()<<endl;
    return 0;
}

