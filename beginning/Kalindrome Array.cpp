// EVERY PROBLEM IS SOLVABLE

#include<bits/stdc++.h>
using namespace std;

#define int long long

bool checkPalindrome(vector<int>& arr, int x){
    int n = arr.size();

    int i = 0;
    int j = n-1;

    while(i < j){
        if(arr[i] == x){
            i++;
        }
        else if(arr[j] == x){
            j--;
        }
        else if(arr[i] != arr[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }

    return true;
}

string solve(){
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }

    bool flag = true;

    for(int i = 0;i < n-i-1;i++){
        if(arr[i] != arr[n-i-1]){
            flag = checkPalindrome(arr, arr[i]) || checkPalindrome(arr, arr[n-i-1]);
            break;
        }
    }

    if(flag == true){
        return "YES";
    }
    else{
        return "NO";
    }
}

signed main(){
    int T;
    cin >> T;

    while(T--){
        cout<<solve()<<endl;
    }

    return 0;
}