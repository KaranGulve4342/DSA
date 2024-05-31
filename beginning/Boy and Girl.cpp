// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    unordered_set<char> uset;

    for(auto ch : str){
        uset.insert(ch);
    }

    if(uset.size()&1){
        cout<<"IGNORE HIM!"<<endl;
    }
    else{
        cout<<"CHAT WITH HER!"<<endl;
    }

    return 0;
}