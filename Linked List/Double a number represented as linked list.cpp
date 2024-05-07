// LEETCODE 2816

#include <bits/stdc++.h>
using namespace std;

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
    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* Next = head;

        while(curr != NULL){
            Next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = Next;
        }

        return prev;
    }
    ListNode* doubleIt(ListNode* head) {
        // long long prod = 0;
        // ListNode* temp = head;
        // while(temp != NULL){
        //     prod *= 10;
        //     prod += temp->val;
        //     temp = temp->next;
        // }

        // prod = 2*prod;
        // if (prod == 0) {
        //     return new ListNode(0);
        // }
        // ListNode* c = new ListNode(0);
        // ListNode* curr = c;
        // while(prod > 0){
        //     curr->next = new ListNode(prod % 10);
        //     curr = curr->next;
        //     prod /= 10;
        // }
        // ListNode *ans = reverseList(c->next);
        // return ans;
        ListNode* dummy = reverseList(head);
        ListNode* temp = dummy;
        int carry = 0;
        while(temp != NULL){
            temp->val = 2 * temp->val + carry;
            if(temp->val > 9){
                carry = temp->val / 10;
                temp->val = temp->val % 10;
            } else {
                carry = 0; // Reset carry if not needed
            }
            temp = temp->next;
        }
        if(carry > 0){
            temp = dummy;
            while(temp->next != NULL){
                temp = temp->next;
            }
            temp->next = new ListNode(carry);
        }
        return reverseList(dummy);

    }
};