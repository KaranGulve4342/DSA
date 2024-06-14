// LEETCODE 23

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
private:
    // ListNode* mergeLists(ListNode* a, ListNode* b){
    //     ListNode* c = new ListNode(100);
    //     ListNode* temp = c;
    //     while(a != NULL && b != NULL){
    //         if(a->val < b->val){
    //             temp->next = a;
    //             a = a->next;
    //             temp = temp->next;
    //         }
    //         else if(a->val == b->val){
    //             temp->next = a;
    //             a = a->next;
    //             temp = temp->next;

    //             temp->next = b;
    //             b = b->next;
    //             temp = temp->next;
    //         }
    //         else{
    //             temp->next = b;
    //             b = b->next;
    //             temp = temp->next;
    //         }
    //     }
    //     if(a == NULL) temp->next = b;
    //     if(b == NULL) temp->next = a;

    //     return c->next;
        
    // }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // if(lists.size() == 0){
        //     return NULL;
        // }

        // while(lists.size() > 1){
        //     ListNode* a = lists[lists.size() - 1];
        //     lists.pop_back();

        //     ListNode* b = lists[lists.size() - 1];
        //     lists.pop_back();

        //     ListNode* c = mergeLists(a, b);

        //     lists.push_back(c);
        // }

        // return lists[0];
        priority_queue<int, vector<int>, greater<int>> pq;

        for(auto list : lists){
            ListNode* temp = list;
            while(temp != NULL){
                pq.push(temp->val);
                temp = temp->next;
            }
        }

        ListNode* c = new ListNode(0);
        ListNode* curr = c;
        while(!pq.empty()){
            curr->next = new ListNode(pq.top());
            pq.pop();
            curr = curr->next;
        }

        return c->next;
    }
};