//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
/* Function to print linked list */


void append(struct Node** headRef, struct Node** tailRef, int newData)
{
	struct Node* new_node = new Node(newData);
	struct Node *last = *headRef;
	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    *tailRef = *headRef;
	    return;
	}
	
	(*tailRef) -> next = new_node;
	*tailRef = (*tailRef) -> next;
}

// A utility function to print a linked list
void printList(Node *head)
{
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}



// } Driver Code Ends

/* Function to print linked list */




class Solution
{
    public:
    // your task is to complete this function
    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;
        
        Node* result = NULL;
        
        // Pick either left or right, and recur
        if (left->data <= right->data) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        
        return result;
    }
    
    // Function to perform merge sort on the linked list
    void mergeSort(Node** headRef) {
        Node* head = *headRef;
        Node* left;
        Node* right;
        
        // Base case: if the list is empty or has only one element
        if (!head || !head->next) return;
        
        // Splitting the list into two halves
        splitList(head, &left, &right);
        
        // Recursively sort the sublists
        mergeSort(&left);
        mergeSort(&right);
        
        // Merge the sorted sublists
        *headRef = merge(left, right);
    }
    
    // Function to split the linked list into two halves
    void splitList(Node* head, Node** leftRef, Node** rightRef) {
        Node* slow = head;
        Node* fast = head->next;
        
        // Advance 'fast' two nodes, and advance 'slow' one node
        while (fast) {
            fast = fast->next;
            if (fast) {
                slow = slow->next;
                fast = fast->next;
            }
        }
        
        // 'slow' is before the midpoint, so split at that point
        *leftRef = head;
        *rightRef = slow->next;
        slow->next = NULL;
    }
    
    // Main sort function to call mergeSort
    void sort(Node **head) {
        mergeSort(head);
    }
};


//{ Driver Code Starts.
int main()
{
	int test;
	cin>>test;
	while(test--)
	{
	    struct Node* head = NULL;
	    struct Node* tail = NULL;
	    int n, k;
	    cin>>n;
	    for(int i=0; i<n ;i++){
	        cin>>k;
	        append(&head, &tail, k);
	    }
	    Solution ob;
	    ob.sort(&head);
	    printList(head);
	}
	return 0;
}

// } Driver Code Ends