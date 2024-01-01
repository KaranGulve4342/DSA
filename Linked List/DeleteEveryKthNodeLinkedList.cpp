// C++ program to delete every k-th Node of
// a singly linked list.
#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node* next;
};

void freeList(Node *node)
{
	while (node != NULL)
	{
		Node *next = node->next;
		delete (node);
		node = next;
	}
}

Node *deleteKthNode(Node *head, int k)
{
	if (head == NULL) return NULL;
	if (k == 1)
	{
        freeList(head);
        return NULL;
	}
	Node *ptr = head;
    Node *prev = NULL;
	int count = 0;
	while (ptr != NULL)
	{
		count++;
		if (k == count)
		{
			delete(prev->next);
			prev->next = ptr->next;
			count = 0;
		}
		if (count != 0) prev = ptr;
	
		ptr = prev->next;
	}

	return head;
}

/* Function to print linked list */
void displayList(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout<<temp->data<<" ";
		temp = temp->next;
	}
}

// Utility function to create a new node.
struct Node *newNode(int x)
{
	Node *temp = new Node;
	temp->data = x;
	temp->next = NULL;
	return temp;
}

/* Driver program to test count function*/
int main()
{
	/* Start with the empty list */
	struct Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
	head->next->next->next->next->next = newNode(6);
	head->next->next->next->next->next->next =
										newNode(7);
	head->next->next->next->next->next->next->next =
										newNode(8);

	int k = 3;
	head = deleteKthNode(head, k);

	displayList(head);

	return 0;
}
