// LEETCODE 1352

#include <bits/stdc++.h>
using namespace std;

class ProductOfNumbers {
public:
    vector<int> arr;
    ProductOfNumbers() {
        
    }   
    
    void add(int num) {
        if(num == 0){
            arr.clear();
            return;
        }

        if(arr.empty()){
            arr.push_back(num);
        }
        else{
            arr.push_back(arr.back() * num);
        }
    }
    
    int getProduct(int k) {
        if(k > arr.size()){
            return 0;
        }

        if(k == arr.size()){
            return arr[k-1];
        }

        return arr.back() / arr[arr.size() - k - 1];
        
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */