// LEETCODE 234

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
    bool isPalindrome(ListNode* head){
        ListNode* c = new Listnode(10);
        // deep copy of head
        ListNode* temp = head;
        ListNode* tempC = c;
        while(temp != NULL){
            ListNode* node = new ListNode(temp->val);
                tempC->next = node;
                temp = temp->next;
                tempC = tempC->next;
        }
        c = c->next;
        c = reverseList(c);
        ListNode* a = head;
        ListNode* b = c;
        while(a != NULL){
            if(a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
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

    bool isPalindrome(ListNode* head){
        // if the first half and the second half are reverse of each other then it is a palindrome
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next->next != NULl){
            slow = slow->next;
            fast = fast->next->next;
        }
        // slow is at the left middle / middle
        ListNode* newHead = reverseList(slow->next);
        ListNode* a = head;
        ListNode* b = newHead;
        while(b){
            if(a->val != b->val) return false;
            a = a->next;
            b = b->next;
        }
        return true;
    }
    
}
*/