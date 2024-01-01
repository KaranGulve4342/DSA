// LEETCODE 206

/*

class Solution{
public:
    ListNode* getNodeAt(ListNode* head,int idx){
        ListNode* temp = head;
        for(int i = 1;i <= idx;i++){
            temp = temp->next;
        }
        return temp;
    }
    ListNode* reverseList(ListNode* head){
        int n = 0;
        ListNode* temp = head;
        while(temp != NULL){
            cout<<temp->val;
            temp = temp->next;
            n++;
        }
        int i = 0;
        int j = n-1;
        while(i < j){
            ListNode* left = getNodeAt(head,i);
            Listnode* right = getNodeAt(head,j);
            int t = left->val;
            left->val = right->val;
            right->val = t;
        }
        return head;
    }

}

*/

/*
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        ListNode*prev = NULL;
        ListNode* curr=  head;
        ListNode* Next = head;
        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

}
*/

/*
class Solution{
public:
    ListNode* reverseList(ListNode* head){
        if(head == NULL || head->next == NULL) return head;
        ListNode* newHead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newHead;
    }

}
*/