// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        vector<int> v(n);

        for(int i = 0;i < n;i++){
            cin >> v[i];
        }

        bool flag = 1;
        while(flag){
            flag = 0;
            for(int i = 1;i < n-1;i++){
                if(v[i] > v[i-1] && v[i] > v[i+1]){
                    flag = 1;
                    swap(v[i],v[i+1]);
                }
            }
        }

        if(is_sorted(v.begin(),v.end())){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}