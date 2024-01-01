// #include<iostream>
// #include<climits>
// #include<stack>
// using namespace std;

// class stack{
//     int capacity;
//     int *arr;
//     int top;
//     public:
//     int Stack(int c) {
//         this->capacity = c;
//         arr = new int[c];
//         this->top = -1;   
//     }

//     void push(int data){
//         if(this->top == this->capacity - 1){
//             cout<<"Overflow\n";
            

//             return;
//         }
//         this->top++;
//         this->arr[this->top] = data;
//     }

//     int pop(){
//         if(this->top == -1){
//             cout<<"Underflow\n";
//             return;
//         }
//         this->top--;
//     }

//     int getTop(){
//         if(this->top == -1){
//             cout<<"Underflow\n";
//             return INT_MIN;
//         }
//         return this->arr[this->top];
//     }

//     bool isEmpty(){
//         return this->top == -1;
//     }

//     int size(){
//         return this->top + 1;
//     }

//     bool isFull(){
//         return this->top == this->capacity - 1;
//     }
// };

// int main(){
//     Stack st(5);
//     st.push(1);
//     st.push(2);
//     st.push(3);
//     cout<<st.getTop()<<"\n";
//     st.push(4);
//     st.push(5);
//     cout<<st.getTop()<<"\n";
//     st.push(8);
//     return 0;
// }

#include<iostream>
#include<climits>
#include<stack>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int d){
        this->data = d;
        this->next = NULL;
    }
};

class Stack{
    Node* head;
    int capacity;
    int currSize;
    public:
    Stack(int c){
        this->capacity = c;
        this->currSize = 0;
        head = NULL;
    }
    bool isEmpty(){
        return this->head == NULL;
    }
    bool isFull(){
        return this->currSize == this->capacity;
    }
    void push(int data){
        if(this->currSize == this->capacity){
            cout<<"Overflow";
            return;
        }
        Node* new_node = new Node(data);
        new_node->next = this->head;
        this->head = new_node;
        this->currSize++;
    }
    int pop(){
        if(this->head == NULL){
            cout<<"Underflow\n";
            return INT_MIN;
        }
        Node* new_head = this->head->next;
        this->head->next = NULL;
        Node* tobeRemoved = this->head;
        int result = tobeRemoved->data;
        delete tobeRemoved;
        this->head = new_head;
        return result;
    }
    int getTop(){
        if(this->head == NULL){
            cout<<"Underflow\n";
            return INT_MIN;
        }
        return this->head->data;
    }
    int size(){
        return this->currSize;
    }
};

int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.getTop()<<"\n";
    st.push(4);
    st.push(5);
    cout<<st.getTop()<<"\n";
    st.push(8);

    st.pop();
    st.pop();

    cout<<st.getTop()<<"\n";
    return 0;


    return 0;
}


