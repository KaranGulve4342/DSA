// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

string solve(){
    int n;
    cin >> n;
    string str;
    cin >> str;

    int anton = 0, danik = 0;\
    for (int i = 0; i < n; i++) {
        if (str[i] == 'A') {
            anton++;
        } else {
            danik++;
        }
    }

    if(anton > danik){
        return "Anton";
    }
    else if(anton < danik){
        return "Danik";
    }
    return "Friendship"; // "Friendship" is the same as "Draw
}

int main(){
    cout<<solve()<<endl;
    return 0;
}
