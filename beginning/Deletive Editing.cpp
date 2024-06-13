// CODEFORCES 900 RATED

#include <bits/stdc++.h>
using namespace std;

string solve(){
    string s, t;
    cin >> s >> t;

    string temp = "";

    vector<char> countS(26, 0);
    vector<char> countT(26, 0);

    for (char c : s) {
        countS[c - 'A']++;
    }

    for (char c : t) {
        countT[c - 'A']++;
    }

    for(char c : s){
        if(countS[c - 'A'] > countT[c - 'A']){
            countS[c - 'A']--;
        }
        else{
            temp += c;
        }
    }

    if(temp == t){
        return "YES";
    }
    else{
        return "NO";
    }
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
}