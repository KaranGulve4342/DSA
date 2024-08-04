// EVERY PROBLEM IS SOLVABLE
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> st;

void buildTree(vector<int>& a, int i, int lo, int hi) {
    if (lo == hi) {
        st[i] = a[lo];
        return;
    }

    int mid = lo + (hi - lo) / 2;

    buildTree(a, 2 * i + 1, lo, mid);
    buildTree(a, 2 * i + 2, mid + 1, hi);

    st[i] = st[2 * i + 1] + st[2 * i + 2];
}

int getSum(int i, int lo, int hi, int l, int r) {
    if (r < lo || l > hi) {
        return 0;
    }

    if (l <= lo && r >= hi) {
        return st[i];
    }

    int mid = lo + (hi - lo) / 2;

    int leftSum = getSum(2 * i + 1, lo, mid, l, r);
    int rightSum = getSum(2 * i + 2, mid + 1, hi, l, r);

    return leftSum + rightSum;
}

signed main() {
    int n, q;
    cin >> n >> q;

    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    
    st.resize(4*n);

    buildTree(a, 0, 0, n - 1);

    while (q--) {

        int l, r;
        cin >> l >> r;

        l--; 
        r--;

        cout << getSum(0, 0, n - 1, l, r) << endl;
    }

    return 0;
}
