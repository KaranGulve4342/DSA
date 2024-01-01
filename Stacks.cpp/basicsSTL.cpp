#include<iostream>
#include<stack>
using namespace std;

int main(){
    stack<int> st;
    cout<<st.size()<<endl;
    st.push(10);
    cout<<st.size()<<endl;
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    cout<<st.size()<<endl;
    // st.pop();
    // cout<<st.size()<<endl;
    // st.pop();
    // cout<<st.size()<<endl;

    // printing in reverse order
    // while(st.size()){
    //     cout<<st.top()<<" ";
    //     st.pop();
    // }

    // we will use extra stack
    stack<int> temp;
    while(st.size()>0){
        cout<<st.top()<<" ";
        temp.push(st.top());
        st.pop();
    }
    // putting elements back from temp to st
    while(temp.size() > 0){
        st.push(temp.top());
        temp.pop();
    }
    cout<<endl<<st.top();




}