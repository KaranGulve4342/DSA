// EVERY PROBLEM IS SOLVABLE

#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> st;

void buildTree(vector<int> &arr, int i, int lo, int hi){
    if(lo == hi){
        st[i] = arr[lo];
        return;
    }

    int mid = lo + (hi - lo) / 2;

    buildTree(arr, 2*i + 1, lo, mid);
    buildTree(arr, 2*i + 2, mid + 1, hi);

    st[i] = min(st[2*i + 1], st[2*i + 2]);
}

int mini(int i, int lo, int hi, int &l, int &r){
    if(lo > r || hi < l){
        return LLONG_MAX;
    }

    if(lo >= l && hi <= r){
        return st[i];
    }

    int mid = lo + (hi - lo) / 2;

    int leftMin = mini(2*i + 1, lo, mid, l, r);
    int rightMin = mini(2*i + 2, mid + 1, hi, l, r);

    return min(leftMin, rightMin);
}

signed main(){
    int n, q;
    cin >> n >> q;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    st.clear();
    st.resize(4*n);
    buildTree(arr, 0, 0, n-1);

    while(q--){
        int l, r;
        cin >> l >> r;

        l--;
        r--;

        cout<<mini(0, 0, n-1, l, r)<<endl;
    }

    return 0;

}