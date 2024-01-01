#include <iostream>
#include <queue>
#include<stack>
using namespace std;

void display_reverse(queue<int>& q){
    stack<int> st;
    // empty thequeue into stack
    while(q.size() > 0){
        int x = q.front();
        q.pop();
        st.push(x);
    }
    // empty the stack into queue
    while(st.size() > 0){
        int x = st.top();
       
        st.pop();
        q.push(x);
    }
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    display_reverse(q);

}