// LEETCODE 1669

/*
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* head=  list1;
        ListNode* newHead = list2;

        

        ListNode* temp = head;
        ListNode* temp2 = newHead;
        a--;
        while(a--){
            temp = temp->next;
        }

        ListNode* Temp = head;
        while(b--){
            Temp = Temp->next;
        }
        Temp = Temp->next;

        while(temp2->next != NULL){
            temp2 = temp2->next;
        }

        temp->next = newHead;
        temp2->next = Temp;

        return head;
        
    }
};
*/