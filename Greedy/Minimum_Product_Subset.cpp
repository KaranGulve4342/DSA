#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int minProduct(vector<int> &arr){
    int count_zero = 0;
    int count_neg = 0;
    int count_pos = 0;
    int prod_neg = 1;
    int prod_pos = 1;
    int largestNeg = INT32_MIN;

    for(int i = 0;i < arr.size();i++){
        if(arr[i] < 0){
            count_neg++;
            prod_neg *= arr[i];
            largestNeg = max(largestNeg, arr[i]);
        }
        if (arr[i] == 0) count_zero++;
        if(arr[i] > 0){
            count_pos++;
            prod_pos *= arr[i];
        }
    }
    if(count_neg == 0){
        if(count_zero > 0) return 0;
        else{
            auto it = min_element(arr.begin(), arr.end());
            return *it;
        }
    }
    else{
        if(count_neg % 2 == 0){
            // even
            return (prod_neg / largestNeg) * prod_pos;
        }
        else{
            // odd
            return prod_neg*prod_pos;
        }
    }
}

int main(){
    vector<int> arr = {11,-1,7,-4,-9};
    cout<<minProduct(arr)<<"\n";
    return 0;
}