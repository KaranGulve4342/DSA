#include<iostream>
#include<queue> // TC => O(n)   SC => O(1)
using namespace std;

void display(queue <int> &q){
    int n = q.size();
    for(int i = 1;i <= n;i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
}

int main(){
    queue<int> q;
    // push
    // pop
    // front -> top
    // size, empty
    // back
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    cout<<q.front()<<endl;
    display(q);
    cout<<"\n";
    q.pop();
    display(q);
    // cout<<q.front()<<endl;
    // cout<<q.back()<<endl;
}