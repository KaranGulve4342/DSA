#include <bits/stdc++.h>
using namespace std;

vector<int> primeNumbers;
vector<int> squares;

bool solve(int target) {
    
    squares.clear();

    for (int prime : primeNumbers) {
        int square = prime * prime;
        if (square < target) {
            squares.push_back(square);
        }
    }
    int n = squares.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                if (squares[i] + squares[j] + squares[k] == target) {
                    return true;
                }
            }
        }
    }

    return false;
}

vector<int> calculatePrimeNumbers(int maxi) {
    vector<int> primeNumbers;
    vector<bool> isPrime(maxi + 1, true);

    for (int karant = 2; karant*karant <= maxi; karant++) {

        if (isPrime[karant]) {
            for (int p = karant * karant; p <= maxi; p += karant) {
                isPrime[p] = false;
            }
        }
    }

    for (int karant = 2; karant <= maxi; karant++) {

        if (isPrime[karant]) {
            primeNumbers.push_back(karant);
        }
    }

    return primeNumbers;
}

int main() {
    int T;
    cin >> T;

    primeNumbers = calculatePrimeNumbers(100000);
    
    while (T--) {
        int target;
        cin >> target;
        if (solve(target)) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}
