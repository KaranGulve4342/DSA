#include <bits/stdc++.h>
using namespace std;

string solve(){
    int N;
    cin >> N; // Read the value of N first
    vector<int> attA(N);
    vector<int> defA(N);
    vector<int> attB(N);
    vector<int> defB(N);
    
    for(int i = 0;i < N;i++){
        cin >> attA[i];
    }
    for(int i = 0;i < N;i++){
        cin >> defA[i];
    }
    for(int i = 0;i < N;i++){
        cin >> attB[i];
    }
    for(int i = 0;i < N;i++){
        cin >> defB[i];
    }
    int sum1A = 0;
    int sum2A = 0;
    int sum1B = 0;
    int sum2B = 0;
    
    for(int i = 0;i < N;i++){
        sum1A += attA[i];
    }
    for(int i = 0;i < N;i++){
        sum2A += defA[i];
    }
    for(int i = 0;i < N;i++){
        sum1B += attB[i];
    }
    for(int i = 0;i < N;i++){
        sum2B += defB[i];
    }

    if(sum1A > sum1B && sum2A > sum2B){
        return "A";
    }
    else if(sum1A < sum1B && sum2A < sum2B){
        return "P";
    }
    else return "DRAW";
}

int main() {
    int T;
    cin >> T; // Read the number of test cases
    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}
