// LEETCODE 430

/*
class Solution{
public:
    Node* flatten(Node* head){
        Node* temp = head;
        while(temp != NULL){
            Node* a = temp->next;
            if(temp->child){
                Node* c = temp->child;
      
                temp->child = NULL; // V IMP
                c = flatten(c); // Recursion
                temp->next = c;
                c->prev = temp;
                while(c->next != NULL){
                    c = c->next;
                }
                c->next = a;
                if(a != NULL) a->prev = c; // error
            }
            temp = a;
        }
        return head;
    }
};
*/