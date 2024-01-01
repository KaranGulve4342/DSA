// LEETCODE 21

// method I
/*
class Solution{
public:
    ListNode* mergeTwoLists(ListNode* a,ListNode* b){
        // SC = O(m+n)
        ListNode* tempA = a;
        ListNode* tempB = b;
        ListNode* c = new ListNode(100);
        ListNode* tempC = c;
        while(tempA!=NULLL && tempB!=NULL){
            if(tempA->val <= tempB->val){
                ListNode* t = new ListNode(tempA->val);
                tempC->next = t;
                tempC = t;
                tempA = tempA->next;
            }
            else{
                ListNode* t = new ListNode(tempB->val);
                tempC->next = t;
                tempC = t;
                tempB = tempB->next;
            }
        }
        if(tempA == NULL){
            tempC->next = tempB;
        }
        else{
            tempC->next = tempA;
        }
        return c->next;
    }
}
*/

// method II
/*
class Solution{
    public:
    ListNode* mergeTwoLists(ListNode* a,ListNode* b){
        SC = O(1)
        ListNode* c = new ListNode(100);
        ListNode* temp = c;
        while(a!=NULL && b!=NULL){
            if(a->val <= b->val){
                
                temp->next = a;
                a = a->next;
                temp = temp->enxt;

            }   
            else{
                // b->val < a->val
                temp->next = b;
                b = b-> next;
                temp = temp->next;
            }
            
            
        }
        if(a == NULL) temp->next = b;
        else temp->next = a;
        return c->next;
    }
};
*/