// CODEFORCERS 800 RATED

#include<bits/stdc++.h>
using namespace std;

int main(){
    string str;
    cin >> str;

    priority_queue<int, vector<int>, greater<int>> pq;

    for(int i = 0;i < str.length();i++){
        if(isdigit(str[i])){
            pq.push(str[i] - '0');
        }
    }
    str = "";
    while(!pq.empty()){
        int digit = pq.top();
        pq.pop();
        str += to_string(digit);
        str += '+';
    }

    str.pop_back();
    cout<<str<<endl;
    return 0;
}