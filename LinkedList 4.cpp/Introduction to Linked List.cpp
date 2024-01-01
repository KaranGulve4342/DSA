#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void display(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
}
void revDisplay(Node* head){
    if(head == NULL) return; // base case
    revDisplay(head->next); // call
    cout<<head->val<<" "; // kaam
}

int size(Node* head){
    Node* temp = head;
    int n = 0;
    while(temp != NULL){
        n++;
        temp = temp->next;
    }
    return n;
}


int main(){
    // Node a(10);
    // Node b(20);
    // Node c(30);
    // Node d(40);
    // // forming Linked List
    // a.next = &b;
    // b.next = &c;
    // c.next = &d;

    // print karani hai d ki value
    // *(*(a.next).next) = c    

    // cout<<(*((*((*(a.next)).next)).next)).val;

    // Node temp = a;
    // while(temp.next != NULL){
    //     cout<<temp.val<<"   ";
    //     temp = (*(temp.next));
    // }

    // while(1){
    //     cout<<temp.val<<" ";
    //     if(temp.next == NULL) break;
    //     temp = *(temp.next);
    // }

    Node* a = new Node(10);
    Node* b = new Node(20);
    Node* c = new Node(30);
    Node* d = new Node(40);

    a->next = b;
    b->next = c;
    c->next = d;

    // cout<<a->next->val;
    // cout<<a->next->next;
    // cout<<a->next->next->val;
    // cout<<a->next->next->next->val;

    // Node* temp = a;
    // while(temp != NULL){
    //     cout<<temp->val<<" ";
    //     temp = temp->next;
    // }
    display(a);
    revDisplay(a);
}
