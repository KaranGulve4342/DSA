#include <bits/stdc++.h>
using namespace std;

vector<int> v;
void buildTree(int arr[], int i, int lo, int hi){
    if(lo == hi){
        v[i] = arr[lo];
        return;
    }
    int mid = lo + (hi - lo)/2;
    buildTree(arr, 2*n + 1, lo, mid);
    buildTree(arr, 2*n + 2, mid+1, hi);

    v[i] = max(v[2*i + 1], v[2*i + 2]);
}
int getMin(int i, int lo, int hi, int& l, int& r){
    if(l > hi || r < lo){
        return INT_MAX;
    }
    if(lo >= l && hi <= r){
        return v[i];
    }

    int mid = lo + (hi - lo)/2;
    int leftMax = getMin(2*i + 1, lo, mid, l, r);
    int rightMax = getMin(2*i + 2, mid + 1, hi, l, r);
    return min(leftMax, rightMax);
}

int main()
{
    int arr[] = {1, 4, 2, 8, 6, 4, 9, 3};
    int n = sizeof(arr)/4;
    st.resize(4*n)
    buildTree(arr, 0, 0, n-1);

    int l, r;
    cout<<"Enter the Range : ";
    cin>>l>>r;
    cout<<getMin(0, 0, n-1, l, r)<<endl;
    
    return 0;
}