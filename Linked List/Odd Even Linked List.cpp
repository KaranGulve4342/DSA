// LEETCODE 328

/*
class Solution{
public:
    ListNode* oddEvenList(ListNode* head){
        if(head == NULL || head->next == NULL || head->next->next == NULL) return head;
        ListNode* Odd = head;
        ListNode* Even = head->next;
        ListNode* tempO = Odd;
        ListNode* tempE = Even;

        while(tempE != NULL && tempE->next != NULL){
            tempO->next = tempE->next;
            tempO = tempO->next;

            tempE->next = tempO->next;
            tempE = tempE->next;
        }
        tempO->next = Even;

        return Odd;
    }
}
*/