#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    node* next;
    node(int n){
        val = n;
        next = NULL;
    }
};
class LinkedList{
    public:
    Node* head;
    Node* tail;
    linkedlist(){
        head = NULL;
        tail = NULL:
    }

    void display(){
        node* temp = head;
        while(temp != NULL){
            cout<<temp->val;
            temp = temp->next;
        }
        cout<<endl;
    }
    void addFirst(int val){
        node* temp = new node(val);
        if(head == NULL) head = temp;
        else{
            temp->next = head;
            head = temp;
        }
        if(tail = NULL) tail = head;
    }
    void addAtIndex(int idx, int val){
        if(idx == 0) addFirst(val);
        else{
            idx--;
            node* temp = head;
            while(idx--){
                temp = temp->next;
            }
            node* newnode = new node(val);
            newnode->next = temp->next;
            temp->next = newnode;
        }
    }
    void getAtIndex(int idx){
        if(idx == 0) cout<<head->val<<endl;
        else{
            node* temp = head;
            while(idx--) temp = temp->next;
            cout<<temp->data<<" ";
        }
    }
    void deleteAtIndex(int idx){
        if(idx == 0) head = head->next;
        else{
            node* prev = NULL;
            node* curr = head;
            while(idx--){
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            curr->next = NULL; 
        }
    }
};
int main(){
    linkedlist ll;
    ll.addFirst(1);
    ll.addFirst(2);
    ll.addFirst(3);
    ll.addFirst(4);
    // ll.display();
    ll.addLast(1);
    ll.addLast(2);
    ll.addLast(3);
    ll.addLast(4);
    ll.addAtIndex(3,8);
    ll.addAtIndex(9,10);
    ll.deleteAtIndex(9);
    ll.display();
    // ll.getAtIndex(9);
}
