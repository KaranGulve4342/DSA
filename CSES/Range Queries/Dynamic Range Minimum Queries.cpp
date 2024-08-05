// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> st;

void buildTree(vector<int>& arr, int i, int lo, int hi){
    if(lo == hi){
        st[i] = arr[lo];
        return;
    }

    int mid = lo + (hi-lo)/2;

    buildTree(arr, 2*i + 1, lo, mid);
    buildTree(arr, 2*i + 2, mid+1, hi);

    st[i] = min(st[2*i + 1], st[2*i + 2]);
}

int getMin(vector<int> &arr, int i, int lo, int hi, int &a, int &b){
    if(lo > b || hi < a){
        return LLONG_MAX;
    }

    if(lo >= a && hi <= b){
        return st[i];
    }

    int mid = lo + (hi-lo)/2;

    int leftMin = getMin(arr, 2*i + 1, lo, mid, a, b);
    int rightMin = getMin(arr, 2*i + 2, mid + 1, hi, a, b);

    return min(leftMin , rightMin);
}

void updateVal(vector<int>& arr, int i, int lo, int hi, int &k, int &u){
    if(lo == hi){
        st[i] = u;
        return;
    }

    int mid = lo + (hi - lo)/2;

    if(k <= mid){
        updateVal(arr, 2*i + 1, lo, mid, k, u);
    }
    else{
        updateVal(arr, 2*i + 2, mid + 1, hi, k, u);
    }

    st[i] = min(st[2*i + 1], st[2*i + 2]);
}


signed main(){
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    st.clear();
    st.resize(4*n);

    buildTree(arr, 0, 0, n-1);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int k, u;
            cin >> k >> u;

            k--;

            updateVal(arr,0,  0, n-1, k, u);
        }
        else{
            int a, b;
            cin >> a >> b;

            a--;
            b--;

            cout<<getMin(arr, 0, 0, n-1, a, b)<<endl;
        }
    }
    return 0;
}