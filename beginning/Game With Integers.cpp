#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n % 3 == 0) {
            cout << "Second" << endl;
        } else {
            int moves = 0;
            while (moves < 10 && n % 3 != 0) {
                n++;
                moves++;
                if (moves < 10 && n % 3 != 0) {
                    n -= 2;
                    moves++;
                }
            }
            if (n % 3 == 0) {
                cout << "First" << endl;
            } else {
                cout << "Second" << endl;
            }
        }
    }
    return 0;
}
