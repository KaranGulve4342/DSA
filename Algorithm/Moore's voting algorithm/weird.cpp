#include<bits/stdc++.h>
using namespace std;

int solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    int count = 1;

    for(int i = 0;i < n-1;i++){
        if(arr[i+1] - arr[i] != 1){
            ++count;
        }
    }
    return count;
}
    


int main(){
    int T;
    cin >>  T;
    while(T--){
        cout<<solve()<<endl;
    }
    return 0;
}