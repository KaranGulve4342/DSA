// Every Sorted Array can be a maxHeap or minHeap.
// But Every maxHeap or minHeap cannot be a Sorted Array

#include <iostream>
#include<vector>
using namespace std;

class MaxHeap{
    vector<int> hp;
    int i; // [0,i] -> maxHeap
    private:
        void upHeapify(int ci){
            while(ci > 0){
                int pi = (ci - 1)/2;
                if(hp[pi] < hp[ci]){
                    swap(hp[pi],hp[ci]);
                    ci = pi;
                }
                else{
                    break;
                }
            }
        }

        void downHeapify(int idx){
            while(idx < hp.size()){
                int lc = 2*idx + 1;
                int rc = 2*idx + 2;
                if(lc >= hp.size()) break; // idx->left;
                int maxEle = idx;
                if(hp[lc] > hp[maxEle]){
                    maxEle = lc;
                }
                if(rc < hp.size() && hp[rc] > hp[maxEle]){
                    maxEle = rc;
                }
                if(maxEle != idx){
                    swap(hp[idx], hp[maxEle]);
                    idx = maxEle; // for next Iteration
                }
                else{
                    break;
                }
            }
        }
    public:
        void push(int element){
            hp.push_back(element);
            upHeapify(hp.size() - 1);
        }

        void pop(){
            // remove the highest priority element
            if(isEmpty()) return;
            swap(hp[0],hp[hp.size() - 1]);
            hp.pop_back();
            if(!isEmpty()){
                downHeapify(0);
            }
            
        }

        bool isEmpty(){
            return hp.size() == 0;
        }

        void display(){
            cout<<"[";
            for(int i = 0;i < hp.size();i++){
                cout<<hp[i]<<" ";
            }
            cout<<"]\n";
        }

        int peek(){
            if(isEmpty()){
                return INT64_MIN;
            }
            return hp[0];
        }

        MaxHeap(vector<int> v){
             // Time COmplexity : O(n.log(n))
            hp = v;
            for(int i = 1;i < hp.size();i++){
                upHeapify(i);
            }
        }
};

int main()
{
    vector<int> v = {9,6,1,19,3,2,8,12,5};
    MaxHeap hp(v);
    hp.display();
    hp.push(100);
    hp.display();

    return 0;
}