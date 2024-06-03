#include<bits/stdc++.h>
using namespace std;

string karan(){
    long long n;
    cin >> n; 
    vector<long long> arr(n);

    vector<long long> m1;
    vector<long long> m2;
    vector<long long> m3;
    vector<long long> newGCD1;
    vector<long long> newGCD2;
    vector<long long> newGCD3;
    bool signal1 = true;
    bool signal2 = true;
    bool signal3 = true;
    
    long long idx = -1;

    for (long long i = 0; i < n; i++) {
        cin >> arr[i];
    }

    vector<long long> gcd_vector;

    for (long long i = 0; i < n - 1; i++) {
        gcd_vector.push_back(__gcd(arr[i], arr[i + 1]));
    }

    for (long long i = 0; i < n - 2; i++) {
        if (gcd_vector[i] > gcd_vector[i + 1]) {
            idx = i;
            break;
        }
    }

    if (idx == -1) {
        return "YES";
    }

    for (long long i = 0; i < n; i++) {
        if (i != idx + 2) {
            m2.push_back(arr[i]);
        }
        if (i != idx + 1) {
            m1.push_back(arr[i]);
        }
        if (i != idx) {
            m3.push_back(arr[i]);
        }
    }

    for (long long i = 0; i < n - 2; i++) {
        newGCD1.push_back(__gcd(m1[i], m1[i + 1]));
        newGCD3.push_back(__gcd(m3[i], m3[i + 1]));
        newGCD2.push_back(__gcd(m2[i], m2[i + 1]));
    }

    for (long long i = 0; i < n - 3; i++) {
        if (newGCD2[i] > newGCD2[i + 1]) {
            signal2 = false;
            break;
        }
    }
    for (long long i = 0; i < n - 3; i++) {
        if (newGCD1[i] > newGCD1[i + 1]) {
            signal1 = false;
            break;
        }
    }
    for (long long i = 0; i < n - 3; i++) {
        if (newGCD3[i] > newGCD3[i + 1]) {
            signal3 = false;
            break;
        }
    }

    if ((signal1 || signal2 || signal3)) return "YES";
    return "NO";
}

int main() {
    int T;
    cin >> T; 
    while (T--) {
        cout<<karan()<<endl;
    }
    return 0;
}