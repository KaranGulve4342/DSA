// #include<bits/stdc++.h>
// using namespace std;
 
// int gcd(int a, int b) {
//     while (b != 0) {
//         int temp = b;
//         b = a % b;
//         a = temp;
//     }
//     return a;
// }
 
// int gcdArray(int arr[], int n) {
//     int result = arr[0];
//     for (int i = 1; i < n; i++) {
//         result = gcd(result, arr[i]);
//     }
//     return result;
// }
 
 
// int solve(){
//     int n;
//     cin >> n;
//     int arr[n];
//     for(int i = 0;i < n;i++){
//         cin >> arr[i];
//     }
    
//     int ans = gcdArray(arr, n); 
//     int sum = 0;
    
//     for(int i = 0;i < n;i++){
//         sum += arr[i];
//     }
    
//     return sum / ans;
// }
 
// int main(){
//     int T;
//     cin >> T;
//     while(T--){
//         cout<<solve()<<endl;
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// int lcm(int a, int b) {
//     return a / gcd(a, b) * b;
// }

int lcmArray(int arr[], int n) {
    int result = arr[0];
    for (int i = 1; i < n; i++) {
        result = gcd(result, arr[i]);
    }
    return result;
}

int solve(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
    }
    
    int LCM = lcmArray(arr, n);
    int sum = 0;
    
    for(int i = 0;i < n;i++){
        sum += arr[i];
    }
    
    return sum / LCM;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        cout << solve() << endl;
    }
    return 0;
}
