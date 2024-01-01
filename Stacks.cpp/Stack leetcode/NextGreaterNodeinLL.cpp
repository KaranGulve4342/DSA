#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class ListNode{ // user defined data type
public:
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        this->next = next;
    }

};
vector<int> nextLargerNodes(ListNode* head){
    stack<ListNode*> st;

    ListNode* temp = head;
    while(temp!=NULL){
        while(!st.empty() && (st.top())->val < temp->val){
            ListNode* help = st.top();
            st.pop();
            help->val = temp->val;
        }
        st.push(temp);
        temp = temp->next;
    }

    while(!st.empty()){
        ListNode* help = st.top();
        st.pop();
        help->val = 0;
    }

    vector<int> answer;
    while (head!=NULL)
    {
        answer.push_back(head->val);
        head = head->next;
    }
    return answer;


}
int main(){
    // head = {2,4,6,4,9,0,3,1,3,5,6};
    cout<<nextLargerNodes(head);
}