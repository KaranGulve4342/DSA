/*
class compare{
public:
    bool operator()(node* a,node* b){
        return a->data > b->data;
    }
};

Node<int>* mergeKlists(vector<Node<int>*> &listArray){
    priority_queue<Node<int>*, vector<Node<int>*>, compare> minheap;

    int k = listArray.size();

    if(k == 0) return NULL:

    // step 1:

    for(int i = 0;i < k;i++){
        if(listArray[i] != NULL){
            minHeap.push(listArray[i]);
        }

    }

    Node<int>* head = NULL;
    Node<int>* tail = NULL;

    while(minHeap.size() > 0){
        Node<int>* top = minHeap.top();
        minHeap.top();

        if(top->next != NULL){
            minHeap.push(top->next);
        }

        if(head == NULL){
            // answer ll is empty
            head = top;
            tail = top;
        }
        else{
            // insert at Linked List
            tail->next = top;
            tail = top;
        }
    }
    return head;
}
*/