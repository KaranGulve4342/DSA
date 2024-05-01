// GFG POTD 1st MAY 2024

//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printlist(Node *head)
{
	if (head==NULL)return;
	while (head != NULL)
	{
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

void append(struct Node** headRef, char data)
{
	struct Node* new_node = new Node(data);
	struct Node *last = *headRef;

	if (*headRef == NULL)
	{
	    *headRef = new_node;
	    return;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new_node;
	return;
}


// } Driver Code Ends
/*
Structure of the node of the linked list is as
struct Node
{
	char data;
	struct Node *next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};
*/

class Solution
{
    public:
    struct Node* arrangeCV(Node *head)
    {
        if (head == NULL || head->next == NULL)
            return head;

        // Initialize pointers for vowels and consonants lists
        Node *vowelHead = NULL, *vowelTail = NULL;
        Node *consonantHead = NULL, *consonantTail = NULL;

        // Traverse the original list and divide nodes into vowel and consonant lists
        while (head != NULL)
        {
            if (isVowel(head->data))
            {
                if (vowelHead == NULL)
                    vowelHead = vowelTail = head;
                else
                {
                    vowelTail->next = head;
                    vowelTail = head;
                }
            }
            else
            {
                if (consonantHead == NULL)
                    consonantHead = consonantTail = head;
                else
                {
                    consonantTail->next = head;
                    consonantTail = head;
                }
            }
            head = head->next;
        }

        // Merge the two lists
        if (vowelHead != NULL)
        {
            head = vowelHead;
            if (consonantHead != NULL)
            {
                vowelTail->next = consonantHead;
                consonantTail->next = NULL;
            }
        }
        else
            head = consonantHead;

        return head;
    }

private:
    // Function to check if a character is a vowel
    bool isVowel(char c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
};


//{ Driver Code Starts.

// task is to complete this function
int main()
{
    int T;
    cin>>T;
    while(T--){
        int n;
        char tmp;
        struct Node *head = NULL;
        cin>>n;
        while(n--){
            cin>>tmp;
            append(&head, tmp);
        }
        Solution obj;
        head = obj.arrangeCV(head);
        printlist(head);
    }
	return 0;
}


// } Driver Code Ends