#include<iostream>
#include<stack>
using namespace std;

class Stack{
    // properties
    public:
        int *arr;
        int top;
        int size;
    // behaviour
    Stack(int size){
        this -> size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int element){
        if(size - top > 1){
            top++;
            arr[top] = element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(top >= 0){
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }

    int peek(){
        if(top >= 0 && top < size)
            return arr[top];
        else{
            cout<<"Stack is Empty"<<endl;
            return -1;
        }
    }
    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else{
            return false;
        }
    }
};

class TwoStack{
    int *arr;
    int top1;
    int top2;
    int size;

    public:
    // Initialize TwoStack
    TwoStack(int s){
        this->size = s;
        top1 = -1;
        top2 = s;
        arr = new int[s];
    }

    // Push in stack 1
    void push1(int num){
        // atlest a empty space present
        if((top2 - top1) > 1){
            top1++;
            arr[top1] = num;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    // Push in stack 2
    void push2(int num){
        if((top2 - top1) > 1){
            top2--;
            arr[top2] = num;
        }
    }
    // Pop from stack 1 and return popped element
    int pop1(){
        if(top1 >= 0){
            int ans = arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }
    // Pop from stack 2 and return popped element.
    int pop2(){
        if(top2 < size){
            int ans = arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }

    
};

int main(){
    /*
    Stack st(5);
    st.push(22);
    st.push(57);
    st.push(78);

    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;

    if(st.isEmpty()){
        cout<<"Stack is Empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    */


    /*
    // creation of stack
    stack<int> s;

    // push operation
    s.push(2);
    s.push(4);

    // pop
    s.pop();

    cout<<"Printing Top Element "<<s.top()<<endl;

    if(s.empty()){
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    return 0;
    */

}