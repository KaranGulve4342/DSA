#include<bits/stdc++.h>
using namespace std;

//  Linked List class node
class Node{ // User defined data type
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList{ // User defined data structure
    public:
    Node* head = NULL;
    Node* tail = NULL;
    int size;
    LinkedList(){
        head = tail = NULL;
        size = 0;
    }

    void insertAtEnd(int val){
        Node* temp = new Node(val);
        if(size == 0) head = tail = temp;
        else{
            tail->next = temp;
            tail = temp;
        }
        size++;
    }
    void display(){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->val<<" ";
            temp = temp->next;
        }
        cout<<endl;    
    }
};
int main(){
    
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.display();
    ll.insertAtEnd(20);
    ll.display();
    ll.insertAtEnd(7560);
    ll.insertAtEnd(540);
    ll.display();
    cout<<ll.size<<endl;
}