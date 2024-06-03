#include <bits/stdc++.h>
using namespace std;

string karan() {
    int n, f, k;
    cin >> n >> f >> k;
    vector<int> a(n);
    
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int favValue = a[f-1];

    sort(a.rbegin(), a.rend());

    int total = count(a.begin(), a.end(), favValue);

    int counter = 0;
    for (int i = 0; i < k; i++) {
        if (a[i] == favValue) {
            counter++;
        }
    }

    if (counter == total) return "YES";
    else if (counter == 0) return "NO";
    return "MAYBE";
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cout << karan() << endl;
    }

    return 0;
}
