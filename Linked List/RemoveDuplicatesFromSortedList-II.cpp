// LEETCODE 82

/*
class Sollution{
    Listnode* deleteDuplicates(ListNode* head){
        class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* c = new ListNode(0);
        ListNode* temp = c;
        if(head == NULL || head->next == NULL) return head;

        c->next = head;

        while(head != NULL){
            if(head->next != NULL && head->val == head->next->val){
                while(head->next != NULL && head->val == head->next->val){
                    head = head->next;
                }
                temp->next = head->next;
            }
            else{
                temp = temp->next;
            }
            head = head->next;
        }
        return c->next;
    }
};
    }
}
*/