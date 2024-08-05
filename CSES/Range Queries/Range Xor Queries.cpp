// EVERY PROBLEM IS SOLVABLE

#include<bits/stdc++.h>
using namespace std;

#define int long long

vector<int> st;

void buildTree(vector<int>& arr, int i, int lo, int hi){
    if(lo == hi){
        st[i] = arr[lo];
        return;
    }

    int mid = lo + (hi - lo)/2;

    buildTree(arr, 2*i + 1, lo, mid);
    buildTree(arr, 2*i + 2, mid + 1, hi);

    st[i] = st[2*i + 1] ^ st[2*i + 2];
}

int getXorVal(vector<int>& arr, int i, int lo, int hi, int &a, int &b){
    if(lo > b || hi < a){
        return 0;
    }

    if(lo >= a && hi <= b){
        return st[i];
    }

    int mid = lo + (hi-lo)/2;

    int leftXorVal = getXorVal(arr, 2*i + 1, lo, mid, a, b);
    int rightXorVal = getXorVal(arr, 2*i + 2, mid + 1, hi, a, b);

    return leftXorVal ^ rightXorVal;
}

signed main(){
    int n,q;
    cin >> n >> q;

    vector<int> arr(n);

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    st.clear();
    st.resize(4*n);

    buildTree(arr, 0, 0, n-1);

    while(q--){
        int a, b;
        cin >> a >> b;

        a--;
        b--;

        cout<<getXorVal(arr, 0, 0, n-1, a, b)<<endl;
    }

    return 0;
}