#include <iostream>
#include <queue>
using namespace std;

void display(queue<int>& q){
    int n = q.size();
    for(int i = 1;i <= n;i++){
        int x = q.front();
        cout<<x<<" ";
        q.pop();
        q.push(x);
    }
    cout<<endl;
}

int main()
{
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    // cout<<q.front()<<endl;
    // q.pop();
    // cout<<q.front()<<endl;
    // cout<<q.back()<<endl;
    // cout<<q.size()<<endl;
    // cout<<q.empty()<<endl;

    // overflow : only happens if we implement the queue via an array if you fill the array

    // underflow : whenever the queue is empty and we try to use this functions such as : pop(), front(), back().
    display(q);
    return 0;
}