// LEETCODE 25

// Ist METHOD
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    int n;
    ListNode* solve(ListNode* head, int k, int i){
        if(i + k - 1 >= n) return head;

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;

        int temp = k;
        while(temp--){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        head->next = solve(Next, k, i+k);
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        n = 0;

        while(temp != NULL){
            n++;
            temp = temp->next;
        }


        return solve(head, k, 0);
    }
};


// IInd METHOD

class Solution {
public:
    int length(ListNode* head) {
        ListNode* temp = head;
        int len = 0;
        while (temp != NULL) {
            temp = temp->next;
            len++;
        }
        return len;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* Next = head;
        while (curr != NULL) {
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = length(head);
        if (head == NULL || head->next == NULL || k > len) {
            return head;
        }

        // Create a dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (len >= k) {
            ListNode* curr = prev->next;
            ListNode* tail = curr;
            for (int i = 1; i < k; i++) {
                tail = tail->next;
            }
            ListNode* nextGroup = tail->next;

            // Disconnect the sublist and reverse it
            tail->next = NULL;
            ListNode* reversedHead = reverseList(curr);
            
            // Reconnect the reversed sublist
            prev->next = reversedHead;
            curr->next = nextGroup;

            // Move prev to the end of the reversed sublist
            prev = curr;
            len -= k;
        }

        // Capture the new head
        ListNode* newHead = dummy->next;
        // Free the dummy node
        delete dummy;

        return newHead;
    }
};
