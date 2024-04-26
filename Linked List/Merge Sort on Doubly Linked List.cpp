// GFG POTD

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next, *prev;

    Node(int x) {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


// } Driver Code Ends

/* Structure of the node of the list is as
struct Node
{
    int data;
    struct Node *next, *prev;
    Node (int x){
        data = x;
        next = prev = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given doubly linked list using Merge Sort.
    Node* merge(Node* left, Node* right, bool increasing) {
        if (!left) return right;
        if (!right) return left;

        if (increasing ? left->data < right->data : left->data > right->data) {
            left->next = merge(left->next, right, increasing);
            left->next->prev = left;
            left->prev = nullptr;
            return left;
        } else {
            right->next = merge(left, right->next, increasing);
            right->next->prev = right;
            right->prev = nullptr;
            return right;
        }
    }

    // Function to split the doubly linked list into two halves.
    void split(Node* head, Node** left, Node** right) {
        Node* slow = head;
        Node* fast = head->next;

        while (fast) {
            fast = fast->next;
            if (fast) {
                fast = fast->next;
                slow = slow->next;
            }
        }

        *left = head;
        *right = slow->next;
        slow->next = nullptr;
        if (*right) (*right)->prev = nullptr;
    }

    // Function to perform Merge Sort on the doubly linked list.
    Node* mergeSort(Node* head, bool increasing) {
        if (!head || !head->next) return head;

        Node *left, *right;
        split(head, &left, &right);

        left = mergeSort(left, increasing);
        right = mergeSort(right, increasing);

        return merge(left, right, increasing);
    }

    // Function to sort the given doubly linked list using Merge Sort.
    Node* sortDoubly(Node* head) {
        return mergeSort(head, true); // Sort in non-decreasing order
    }
};


//{ Driver Code Starts.

void insert(struct Node **head, int data) {
    struct Node *temp = new Node(data);
    if (!(*head))
        (*head) = temp;
    else {
        temp->next = *head;
        (*head)->prev = temp;
        (*head) = temp;
    }
}

void print(struct Node *head) {
    struct Node *temp = head;
    while (head) {
        cout << head->data << ' ';
        temp = head;
        head = head->next;
    }
    cout << endl;
    while (temp) {
        cout << temp->data << ' ';
        temp = temp->prev;
    }
    cout << endl;
}

// Utility function to swap two integers
void swap(int *A, int *B) {
    int temp = *A;
    *A = *B;
    *B = temp;
}

// Driver program
int main(void) {
    long test;
    cin >> test;
    while (test--) {
        int n, tmp;
        struct Node *head = NULL;
        cin >> n;
        while (n--) {
            cin >> tmp;
            insert(&head, tmp);
        }
        Solution ob;
        head = ob.sortDoubly(head);
        print(head);
    }
    return 0;
}

// } Driver Code Ends