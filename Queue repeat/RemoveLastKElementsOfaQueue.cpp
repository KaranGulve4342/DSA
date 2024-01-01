#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    queue<int> q;
    for(int i = 0;i < n;i++){
        int val;
        cin>>val;
        q.push(val);
    }

    int o = n - k;
    while(o--){
        q.push(q.front());
        q.pop();
    }
    while(k--){
        q.pop();
    }
    while(q.size()){
        cout<<q.front()<<" ";
        q.pop();
    }
}