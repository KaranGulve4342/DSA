// CODEFORCES 900 RATED

#include <bits/stdc++.h>
using namespace std;

string solve(){
    string str;
    cin >> str;

    int count1 = 0;
    int count0 = 0;

    for(char ch : str){
        if(ch == '1'){
            count1++;
        }else{
            count0++;
        }
    }
    int k = min(count1, count0);
    if(k&1) return "DA";
    return "NET";
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}
