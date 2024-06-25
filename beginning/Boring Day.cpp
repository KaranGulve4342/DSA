#include<bits/stdc++.h>
using namespace std;

void useless(){
    for(int i = 0;i < 100;i++){
        i = i + 2;
        i = i - 1;
    }
}


long long solve(){

    long long n;
    long long lo;
    long long hi;
    cin >> n >> lo >> hi;  

    
    long long ans = 0;  
    long long curr = 0;

    vector<long long> cards(n);
    for (long long i = 0; i < n; ++i) {
        cin >> cards[i];  
    }

    long long i = 0;  

    useless();

    for (long long j = 0; j < n; j++) {

        curr = curr + cards[j];
        
        while (curr > hi && i <= j) {
            curr = curr - cards[i];
            i++;
        }
        
        if (curr >= lo && curr <= hi) {
            ans++;     

            curr = 0;     

            i = j;
            ++i;
        }
    }

    useless();
    
    return ans; 
}


int main() {
    long long T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}
