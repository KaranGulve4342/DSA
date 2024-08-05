// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> st;
void buildTree(vector<int>&a, int i, int lo, int hi){
    if(lo == hi){
        st[i] = a[lo];
        return;
    }

    int mid = lo + (hi - lo)/2;

    buildTree(a, 2*i + 1, lo, mid);
    buildTree(a, 2*i + 2, mid + 1, hi);

    st[i] = st[2*i + 1] + st[2*i + 2];
}

int getSum(int i, int lo, int hi, int &a, int &b){
    if(a > hi || b < lo){
        return 0;
    }

    if(lo >= a && hi <= b){
        return st[i];
    }

    int mid = lo + (hi - lo)/2;

    int leftSum = getSum(2*i + 1, lo, mid, a, b);
    int rightSum = getSum(2*i + 2, mid + 1, hi, a, b);

    return leftSum + rightSum;
}

void updateVal(int i, int lo, int hi, int &k, int &u){
    if(lo == hi){
        st[i] = u;
        return;
    }

    int mid = lo + (hi - lo)/2;

    if(k <= mid){
        updateVal(2*i + 1, lo, mid, k, u);
    }
    else{
        updateVal(2*i + 2, mid + 1, hi, k, u);
    }

    st[i] = st[2*i + 1] + st[2*i + 2]; 
}


signed main(){
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for(int i = 0;i < n;i++){
        cin >> a[i];
    }

    st.clear();
    st.resize(4*n);

    buildTree(a, 0, 0, n-1);

    while(q--){
        int type;
        cin >> type;

        if(type == 1){
            int k, u;
            cin >> k >> u;

            k--;

            updateVal(0, 0, n-1, k, u);
        }
        else{
            int a, b;
            cin >> a >> b;

            a--;
            b--;

            cout<<getSum(0, 0, n-1, a, b)<<endl;
        }
    }

    return 0;
}