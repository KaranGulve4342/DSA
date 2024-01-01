#include<iostream>
using namespace std;

class Node{
    // Doubly Linked List Node

public:
    int val;
    Node* next;
    Node* prev; // extra for doubly Linked List
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
}

class DLL{
public:
    Node* head;
    Node* tail;
    int size;
    DLL(){
        head = tail = NULL;
        size = 0;
    }
    void insertAtTail(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    void insertAtHead(int val){
        Node* temp = new node(val);
        if(size == 0) head = tail = temp;
        else{
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
        size++;
    }
    void insertAtIndex(int idx, int val){
        if(idx < 0 || idx > size) cout<<"Invalid Index"<<endl;
        else if(idx == 0) insertAtHead(val);
        else if(idx == size) insertAtTail(val);
        else{
            Node* t = new Node(val);
            Node* temp = head;
            for(int i = 1;i <= idx - 1;i++){
                temp = temp->next;
            }
            t->next = temp->next;
            temp->next = t;
            t->prev = temp;
            t->next->prev = t;
            size++;
        }
    }
}
void deleteAtHead(){
    if(size() == 0){
        cout<<"List is Empty!";
        return;
    }
    head = head->next;
    if(head == NULL) head->prev== NULL;
    if(head == NULL) tail = NULL; 
    size--;
}
void deleteAtTail(){
    if(size == 0){
        cout<<"List is Empty!";
        return;
    }
    else if(size == 1){
        deleteAtHead();
        return;
    }
    Node* temp = tail->prev;
    temp->next = NULL;
    tail=  temp;
}

// #include<iostream>
// using namespace std;

// class Node{
// public:
//     int val;
//     Node* next;
//     Node(int val){
//         this->val = val;
//         this->next = NULL;
//     }
// };

// class LinkedList{
//     public:
//     Node* head;
//     Node* tail;
//     LinkedList(){
//         head = NULL;
//         tail = NULL;
//     }

//     void display(){
//         Node* temp = head;
//         while(temp != NULL){
//             cout<<temp->val;
//             temp = temp->next;
//         }
//         cout<<endl;
//     }

//     void addFirst(int val){
//         Node* temp = new Node(val);
//         if(head == NULL) head = temp;
//         else{
//             temp->next = head;
//             head = temp;
//         }
//         if(tail == NULL) tail = head;
//     }
//     void addAtIndex(int idx, int val){
//         if(idx == 0) addFirst(val);
//         else{
//             idx--;
//             Node* temp = head;
//             while(idx--){
//                 temp = temp->next;
//             }
//             Node* newNode = new Node(val);
//             newNode->next = temp->next;
//             temp->next = newNode;
//         }
//     }
//     void getAtIndex(int idx){
//         if(idx == 0) cout<<head->val<<endl;
//         else{
//             Node* temp = head;
//             while(idx--) temp = temp->next;
//             cout<<temp->val;
//         }
//     }
//     void deleteAtIndex(int idx){
//         if(idx == 0) head = head->next;
//         else{
//             Node* temp = head;
//             idx--;

//             while(idx--){
//                 temp = temp->next;
//             }
//             temp->next = temp->next->next;
//         }
//     }

// }

// void display(Node* head){
//     Node* temp = head;
//     while(temp != NULL){
//         cout<<temp->val<<" ";
//         temp = temp->next;
//     }
// }

// void revDisplay(Node* head){
//     if(head == NULL) return; // base case
//     revDisplay(head->next); // call
//     cout<<head->val<<" ";
// }

// int size(Node* temp){
//     Node* temp = head;
//     int n = 0;
//     while(temp != NULL){
//         n++;
//         temp = temp->next;
//     }
//     return n;
// }






// int main() {
//     Node* a = new Node(10);
//     Node* b = new Node(20);
//     Node* c=  new Node(30);
//     Node* d = new Node(40);

//     a->next = b;
//     b->next = c;
//     c->next=  d;

//     display(a);
//     revDisplay(a);
// }