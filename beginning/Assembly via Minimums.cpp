// CODEFORCES 1200 RATED

// EVERY PROBLEM IS S0LVABLE

#include<bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin >> T;

    while(T--){
        int n;
        cin >> n;

        int total = ((n)*(n-1))/2;

        int arr[total];

        for(int i=0; i<total; i++){
            cin >> arr[i];
        }

        sort(arr, arr+total);
        int last = 0;

        for(int i = 1;i < n;i++){
            cout<<arr[last]<<" ";
            last += (n-i);
        }

        int maxi = 1e9;
        cout<<maxi<<endl;
    }
    return 0;
}