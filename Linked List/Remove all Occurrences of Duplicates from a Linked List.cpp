// GFG

//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
         if (!head || !head->next) return head;
        
        // Dummy node to handle edge cases
        Node* dummy = new Node(0);
        dummy->next = head;
        
        Node* prev = dummy;
        Node* current = head;
        
        while (current) {
            // Check if the current node is a duplicate
            bool isDuplicate = false;
            while (current->next && current->data == current->next->data) {
                isDuplicate = true;
                current = current->next;
            }
            
            if (isDuplicate) {
                // Skip all duplicates
                prev->next = current->next;
            } else {
                // Move prev to next only if no duplicate
                prev = prev->next;
            }
            current = current->next;
        }
        
        // Return the head of the modified list
        return dummy->next;
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends