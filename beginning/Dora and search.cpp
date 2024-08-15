// CODEFORCES 1200 RATED

#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
    int n;
    cin >> n;
    set<int> st;
    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        st.insert(arr[i]);
    }

    int lo = 0;
    int hi = n-1;

    while((hi - lo) > 1){
        int mini = *st.begin();
        int maxi = *st.rbegin();

        if(arr[lo] != mini && arr[lo] != maxi && arr[hi] != mini && arr[hi] != maxi){
            break;
        }
        if(arr[lo] == mini || arr[lo] == maxi){
            st.erase(arr[lo]);
            lo++;
        }
        if(arr[hi] == mini || arr[hi] == maxi){
            st.erase(arr[hi]);
            hi--;
        }
    }

    if(hi - lo > 1){
        cout<<lo+1<<" "<<hi+1<<endl;
    }
    else{
        cout<<-1<<endl;
    }
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        solve();
    }
}