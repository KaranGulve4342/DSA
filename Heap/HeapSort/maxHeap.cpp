/*
#include <iostream>
#include<vector>
using namespace std;

class MaxHeap{
    vector<int> hp;
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
};

int main()
{
    MaxHeap hp;
    hp.push(3);
    hp.push(4);
    hp.push(11);
    hp.push(9);
    hp.push(14);
    hp.push(-1);
    hp.push(30);
    hp.push(44);
    hp.push(50);
    hp.display();
    cout<<hp.peek()<<"\n";
    hp.pop();
    hp.display();
    
    return 0;
}
*/

#include<iostream>
#include<vector>
using namespace std;

class MaxHeap {
    vector<int> hp;
public:
    void upheapify(int ci){
        while(ci > 0){
            int pi = (ci - 1)/2;
            if(hp[pi] < hp[ci]) {
                swap(hp[pi], hp[ci]);
                ci = pi;
            }
            else{
                break;
            }
        }
    }
    void downheapify(int idx){
        while(idx < hp.size()){
            int lc = 2*idx + 1;
            int rc = 2*idx + 2;

            if(lc >= hp.size()) break; // idx->left
            int maxEl = idx;
            if(hp[lc] > hp[maxEl]){
                maxEl = lc;
            }
            if(rc < hp.size() && hp[rc] > hp[maxEl]){
                maxEl = rc;
            }
            if(maxEl != idx){
                swap(hp[idx], hp[maxEl]);
                idx = maxEl;
            }
            else{
                break;
            }
        }
    }

    void push(int element){
        hp.push_back(element);
        upheapify(hp.size()-1);
    }

    void pop(){
        // removes the highest priority element
        if(empty()) return;
        swap(hp[0], hp[hp.size() - 1]);
        hp.pop_back();
        if(!empty()){
            downheapify(0);
        }
    }

    int peek(){
        if(empty()) return INT32_MIN;
        return hp[0];
    }

    bool empty(){
        return hp.size()==0;
    }

    void display(){
        cout<<"[";
        for(int i = 0;i < hp.size(); i++){
            cout<<hp[i]<<" ";
        }
        cout<<"]\n";
    }
};

int main(){
    MaxHeap hp;
    hp.push(3);
    hp.push(6);
    hp.push(1);
    hp.push(-9);
    hp.push(0);
    hp.push(7);
    hp.push(2);
    hp.push(-8);
    hp.push(9);
    hp.push(4);
    hp.push(67);

    hp.display();

    hp.pop();
    hp.display();

    return 0;
}