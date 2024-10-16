#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int> arr, int n, int x){
    int lo = 0;
    int hi = n-1;

    int ans = n;

    while(lo <= hi){
        int mid = lo + (hi - lo)/2;

        if(arr[mid] >= x){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }
    return ans;
}
int upperBound(vector<int> arr, int n, int x){
    int lo = 0;
    int hi = n-1;
    int ans = n;

    while(lo <= hi){
        int mid = lo + (hi - lo)/2;

        if(arr[mid] > x){
            ans = mid;
            hi = mid - 1;
        }
        else{
            lo = mid + 1;
        }
    }

    return ans;
}
pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k){
    int lb = lowerBound(arr, n, k);

    if(lb == n || arr[lb] != k){
        return {-1, -1};
    }

    return {lb, upperBound(arr, n, k) - 1};
}