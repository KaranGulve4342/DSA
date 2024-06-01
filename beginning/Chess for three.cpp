// CODEFORCES 900 RATED

#include<bits/stdc++.h>
using namespace std;

int solve(){
    int p, q, r;
    cin >> p >> q >> r;

    priority_queue<int> pq;
    if(p > 0){
        pq.push(p);
    }
    if(q > 0){
        pq.push(q);
    }
    if(r > 0){
        pq.push(r);
    }
    int count = 0;
    while(pq.size() > 1){
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        count++;
        first -= 1;
        second -= 1;

        if(first > 0) pq.push(first);
        if(second > 0) pq.push(second);
    }

    if(pq.size() > 0 && pq.top()&1){
        return -1;
    }
    return count;
}

int main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}