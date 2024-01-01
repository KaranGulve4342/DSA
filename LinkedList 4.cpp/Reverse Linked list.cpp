// Leetcode 206

/*
class Solution{
    public:
    ListNode* getNodeAt(ListNode* head,int idx){
        ListNode* temp = head;
        // 1 2 3 4 5
        for(int i = 1;i <= idx;i++){
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head){
        int n = 0;
        ListNode* temp = head;
        while(temp){
            cout<<temp->val;
            temp = temp->next;
            n++;
        }
        int i = 0;
        int j = n - 1;
        while(i < j){
            ListNode left = getNodeAt(head,i);
            ListNode right = getNodeAt(head,j);
            int t = left->val;
            left->val = right->val;
            right->val = t;
            i++;
            j--;
        }
        return head;
    }
};

*/

/*

class Solution{
    public:
    ListNode* reverseList(ListNode* head){
        ListNode *prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while(curr){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next
        }
        return prev;
    }
};

*/

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};

Node *newNode(int data)
{
    Node *temp=new Node(data);
    
    return temp;
}




void displayList(Node *head)
{
    //Head to Tail
    while(head->next)
    {
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<head->data;
    
    
    
}


int getLength(Node * head)
{
    Node *temp=head;
    
    int count=0;
    while(temp->next!=head)
    {
        count++;
        temp=temp->next;
    }
    return count+1;
}




bool verify(Node* head)
{
    int fl=0;
    int bl=0;
    
    Node *temp=head;
    
    while(temp->next)
    {
        temp=temp->next;
        fl++;
    }
    
    while(temp->prev)
    {
        temp=temp->prev;
        bl++;
    }
    
    return fl==bl;
}


// } Driver Code Ends
/*
struct Node
{
    int data;
    Node * next;
    Node * prev;
    Node (int x)
    {
        data=x;
        next=NULL;
        prev=NULL;
    }
        
};
*/
class Solution
{
    public:
    Node* reverseDLL(Node * head)
    {
        //Your code here
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        
        Node* prev = NULL;
        Node* curr = head;
        Node* Next = head;
        
        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            curr->prev = Next;
            prev = curr;
            curr = Next;
        }
        head = prev;
        return head;
    }
};



//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    Node *head=NULL, *tail=NULL;
        int x;
	    cin>>x;
	    head = newNode(x);
	    tail = head;
	    
	    for(int i=0;i<n - 1;i++)
	    {
	        cin>>x;
	        Node* temp=newNode(x);
	        tail->next=temp;
	        temp->prev= tail;
	        tail = temp;
	    }
	    Solution ob;
	    head=ob.reverseDLL(head);
	    
	    
	    if(verify(head))
	    displayList(head);
	    else
	    cout<<"Your pointers are not correctly connected";
 
	    cout<<endl;
	}
	return 0;
}


// } Driver Code Ends