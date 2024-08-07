// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    string str;
    cin >> str;

    unordered_map<char, int> mp;
    for(auto ch : str){
        mp[ch]++;
    }

    int odd = 0;
    char odd_char;
    for(auto it : mp){
        if(it.second % 2 == 1){
            odd++;
            odd_char = it.first;
        }
    }

    if(odd > 1){
        cout<<"NO SOLUTION"<<endl;
        return 0;
    }

    string ans = "";

    for(auto it : mp){
        if(it.second % 2 == 0){
            for(int i = 0;i < it.second/2;i++){
                ans += it.first;
            }
        }
    }

    string ans2 = ans;
    reverse(ans2.begin(), ans2.end());

    if(odd == 1){
        for(int i = 0;i < mp[odd_char];i++){
            ans += odd_char;
        }
    }

    cout<<ans+ans2<<endl;

    return 0;

}