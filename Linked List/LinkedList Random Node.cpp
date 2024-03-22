// LEETCODE 382

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
    vector<int> v;
    Solution(ListNode* head) {
        ListNode* curr = head;
        while(curr != NULL){
            v.push_back(curr->val);
            curr = curr->next;
        }
    }
    
    int getRandom() {
        int randomIndex = rand() % v.size();
        return v[randomIndex];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */\

// Using Reservior Sampling


class Solution {
public:
    ListNode* head = NULL;    // head node of the linked list

    Solution(ListNode* head) {
        this->head = head;     // initialize head node
    }

    /**
    * getRandom function to get a random value from the linked list.
    * This function uses reservoir sampling to ensure that each element
    * has an equal probability of being selected.
    *
    * @return int - a random value from the linked list
    */
    int getRandom() {
        int ans = 0;           // variable to store the answer
        int i = 1;              // counter for the number of elements
        ListNode* curr = this->head;  // current node in the linked list

        while (curr != NULL) {
            // if the current element is the first element, set it as the answer
            if (rand() % i == 0) {
                ans = curr->val;
            }

            i++;                 // increment the counter
            curr = curr->next;   // move to the next node
        }

        return ans;            // return the answer
    }
};
