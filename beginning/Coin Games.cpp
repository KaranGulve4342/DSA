// CODEFORCES 900 RATED

#include<bits/stdc++.h>
using namespace std;

string solve(){
    int n;
    string str;
    cin >> n >> str;

    int upCount = 0;

    for(int i = 0; i < n; i++){
        if(str[i] == 'U'){
            upCount++;
        }
    }

    if(upCount % 2 == 1){
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

    return 0;
}