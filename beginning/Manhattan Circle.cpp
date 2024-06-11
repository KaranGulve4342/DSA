// CODEFORCES CONTEST KARAN

#include <bits/stdc++.h>
using namespace std;

void solve(){
    int rows, cols;
    cin >> rows >> cols;

    vector<string> grid(rows);


    for (int i = 0; i < rows; ++i) {
        cin >> grid[i];
    }

    int leftMost = cols;
    int rightMost = -1;
    int maxHashCount = 0;

    for (auto row : grid) {
        int currentCount = 0;
        int firstHash = -1, lastHash = -1;

        for (int j = 0; j < cols; ++j) {
            if (row[j] == '#') {
                currentCount++;
                if (firstHash == -1) {
                    firstHash = j;
                }
                lastHash = j;
            }
        }

        if (firstHash != -1) {
            leftMost = min(leftMost, firstHash);
            rightMost = max(rightMost, lastHash);
        }

        maxHashCount = max(maxHashCount, currentCount);
    }

    int resultRow = -1;
    // Find the row that contains the maximum number of '#'
    for (int i = 0; i < rows; ++i) {
        int currentCount = count(grid[i].begin(), grid[i].end(), '#');
        if (currentCount == maxHashCount) {
            resultRow = i;
            break;
        }
    }

    int middleColumn = (leftMost + rightMost) / 2 + 1;
    cout << resultRow + 1 << " " << middleColumn << endl;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        karan();
    }

    return 0;
}
