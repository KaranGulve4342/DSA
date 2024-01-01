// LEETCODE 23

#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    ListNode* mergeKLists(vector<ListNode *> &lists){
        priority_queue<int, vector<int>, greater<int>> min_heap;
        for(auto list : lists){
            while(list->next != NULL){
                min_heap.push(list->val);
                list = list->next;
            }
        }
        if(min_heap.empty()){
            return NULL;
        }
        ListNode* res = new ListNode(min_heap.top());
        min_heap.pop();
        ListNode *current = res;
        while(!minheap.empty()){
            current->next = new ListNode(min_heap.top());
            current = current->next;
            minheap.pop();
        }
        return res;
    }
}

int main()
{
    
    
    return 0;
}