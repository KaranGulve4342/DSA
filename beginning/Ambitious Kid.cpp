// CODEFORCES 800 RATED

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> arr(n);
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        if(arr[i] < 0){
            arr[i] *= (-1);
        }
    }

    cout<<*min_element(arr.begin(), arr.end())<<endl;
    return 0;
}