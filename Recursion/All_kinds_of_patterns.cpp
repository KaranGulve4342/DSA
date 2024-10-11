#include<bits/stdc++.h>
using namespace std;

#define int long long 

// void printS(int i, vector<int>&ds, int s, int sum, int arr[], int n){
//     if(i == n){
//         if(s == sum){
//             for(auto it : ds){
//                 cout<<it<<" ";
//             }
//             cout<<endl;
//         }
//         return;
//     }

//     ds.push_back(arr[i]);
//     sum += arr[i];

//     printS(i+1, ds, s, sum, arr, n);

//     ds.pop_back();
//     sum -= arr[i];

//     printS(i+1, ds, s, sum, arr, n);
// }


// signed main(){
//     int arr[] = {1, 2, 1};
//     int n = 3;
//     int sum = 2;

//     vector<int> ds;

//     printS(0, ds, 0, sum, arr, n);

//     return 0;
// }


// for counting the number of subsets
int printS(int idx, int s, int sum, int arr[], int n){
    if(idx == n){
        if(s == sum){
            return 1;
        }
        else return 0;
    }

    s += arr[idx];

    int l = printS(idx + 1, s, sum, arr, n);

    s -= arr[idx];

    int r = printS(idx + 1, s, sum, arr, n);

    return l+r;
}

signed main(){
    int arr[] = {1, 2, 1};
    int n = 3;
    int sum = 2;

    cout<<printS(0, 0, sum, arr, n);

    return 0;
}