// LEETCODE 2807

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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* temp = head;
        while(temp != NULL && temp->next != NULL){
            int gcd = __gcd(temp->val, temp->next->val);
            ListNode* extra = temp->next;
            ListNode* gcdNode = new ListNode(gcd);

            gcdNode->next = temp->next;
            temp->next = gcdNode;
            temp = gcdNode->next;
        }
        return head;
    }
};