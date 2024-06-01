// CODEFORCES 800 RATED

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    bool flag = false;

    while(n--){
        int bit;
        cin >> bit;

        if(bit == 1){
            flag = true;
        }
    }

    if(flag == true){
        cout<<"HARD"<<endl;
    }
    else{
        cout<<"EASY"<<endl;
    }

    return 0;
}