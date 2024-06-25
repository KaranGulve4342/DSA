// CODEFORCES 1000 RATED;

#include <bits/stdc++.h>
using namespace std;

int solve(){
    string str;
    cin >> str;
    int n = str.length();

    int count0 = 0;
    int count1 = 0;

    for(int i = 0;i < str.length();i++){
        if(str[i] == '0'){
            count0++;
        }
        else{
            count1++;
        }
    }
    int i;
    for(i = 0;i < n;i++){
        if(str[i] == '0'){
            if(count1 > 0){
                count1--;
            }
            else{
                break;
            }
        }
        else{
            if(count0 > 0){
                count0--;
            }
            else{
                break;
            }
        }
    }
    return n-i;

}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}