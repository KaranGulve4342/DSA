// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    // int num1, num2;

    // int ans = 0;

    // while(num1 && num2){
    //     int a = num1 % 10;
    //     int b = num2 % 10;

    //     if(a != b){
    //         ans = ans * 10 + 1;
    //     }
    //     else{
    //         ans = ans * 10;
    //     }

    //     num1 /= 10;
    //     num2 /= 10;
    // }
    // cout << ans << endl;

    string s1, s2;
    cin >> s1 >> s2;
    for (size_t i = 0; i < s1.length(); ++i)
    {
        if (s1[i] == s2[i])
        {
            s1[i] = '0';
        }
        else
        {
            s1[i] = '1';
        }
    }
    cout << s1 << endl;
    return 0;
}