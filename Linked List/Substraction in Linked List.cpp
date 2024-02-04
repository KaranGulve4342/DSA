// GFG POTD 4 FEB 2024

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int length(Node* n){
        int ret = 0;
        while(n != NULL){
            ret++;
            n = n->next;
        }
        return ret;
    }
    Node* reverseLinkedList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    Node* subLinkedList(Node* head1, Node* head2) {
        while(head1 != NULL && head1->data == 0){
            head1 = head1->next;   
        }
        while(head2 != NULL && head2->data == 0){
            head2 = head2->next;   
        }
        
        int n1 = length(head1);
        int n2 = length(head2);
        
        if(n1 == 0 && n2 == 0){
            return new Node(0);
        }
        
        if(n2 > n1){
            Node *temp = head1;
            head1 = head2;
            head2 = temp;
        }
        
        if(n1 == n2){
            Node* temp1 = head1;
            Node* temp2 = head2;
            
            while(temp1->data == temp2->data){
                temp1 = temp1->next;
                temp2 = temp2->next;
                
                if(temp1 == NULL){
                    return new Node(0);
                }
            }
            
            if(temp2->data > temp1->data){
                Node* temp = head1;
                head1 = head2;
                head2 = temp;
            }
            
        }
        
        head1 = reverseLinkedList(head1);
        head2 = reverseLinkedList(head2);
        
        Node* ans = NULL;
        Node* temp1 = head1;
        Node* temp2 = head2;
        
        while(temp1 != NULL){
            int less = 0;
            if(temp2 != NULL){
                less = temp2->data;
            }
            if(temp1->data < less){
                if(temp1->next != NULL){
                    temp1->next->data -= 1;
                }
                temp1->data += 10;
            }
            Node* ne = new Node(temp1->data - less);
            ne->next = ans;
            ans = ne;
            temp1 = temp1->next;
            if(temp2!=NULL){
                temp2 = temp2->next;
            }
        }
        while(ans != NULL && ans->next != NULL && ans->data == 0){
            ans = ans->next;
        }
        return ans;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends