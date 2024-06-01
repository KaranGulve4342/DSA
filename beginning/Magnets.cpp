// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string total = "";
    while(n--){
        string temp;
        cin >> temp;
        total += temp;
    }
    int count = 0;
    for(int i = 0;i < total.length() - 1;i++){
        if(total[i] == total[i-1]){
            count++;
        }
    }

    cout<<count+1<<endl;
    return 0;
}