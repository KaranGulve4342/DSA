// LEETCODE 1670

#include <bits/stdc++.h>
using namespace std;

class FrontMiddleBackQueue {
public:
    vector<int> arr;
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        arr.insert(arr.begin(), val);
    }
    
    void pushMiddle(int val) {
        auto middle = arr.begin() + arr.size() / 2;
        arr.insert(middle, val);
    }
    
    void pushBack(int val) {
        arr.push_back(val);
    }
    
    int popFront() {
        if (arr.empty()) return -1;
        int first = arr.front();
        arr.erase(arr.begin());
        return first;
    }
    
    int popMiddle() {
        if (arr.empty()) return -1; 
        int middleIndex = (arr.size() - 1) / 2;
        int middleElement = arr[middleIndex];
        arr.erase(arr.begin() + middleIndex);
        return middleElement;
    }
    
    int popBack() {
        if (arr.empty()) return -1;
        int last = arr.back();
        arr.pop_back();
        return last;
    }
};

/**
 * Your FrontMiddleBackQueue object will be instantiated and called as such:
 * FrontMiddleBackQueue* obj = new FrontMiddleBackQueue();
 * obj->pushFront(val);
 * obj->pushMiddle(val);
 * obj->pushBack(val);
 * int param_4 = obj->popFront();
 * int param_5 = obj->popMiddle();
 * int param_6 = obj->popBack();
 */