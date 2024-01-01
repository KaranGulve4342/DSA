// LEETCODE 1290

/*
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        ListNode* temp = head;
        string str = "";
        while(temp != NULL){
            str += to_string(temp->val);
            temp = temp->next;
        }
        int n =  str.length();
        int result = 0;
        for(int i = n - 1;i >= 0;i--){
            char ch = str[i];
            int num = ch - '0';
            result = result + num*(1 << (n-i-1));
        }
        return result;

    }
};
*/