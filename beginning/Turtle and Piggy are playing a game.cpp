// CODEFORCES CONTEST 31ST MAY 2024

#include <iostream>
using namespace std;

int karan(int l, int r) {
    int x = r;
    int score = 0;
    
    while(x > 1){
        x /= 2;
        score++;
    }
    return score;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int l, r;
        cin >> l >> r;
        cout << karan(l, r) << endl;
    }
    return 0;
}
