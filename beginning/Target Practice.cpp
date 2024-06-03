// CODEFORCES 800 RATED

#include <iostream>
#include <vector>
using namespace std;

// Function to calculate points for a single test case
int calculatePoints(vector<string>& grid) {
    int points = 0;
    // Points array indicating the score of each ring
    int ringPoints[10] = {1, 1, 1, 2, 2, 3, 3, 4, 4, 5};

    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            if (grid[i][j] == 'X') {
                // Calculate the minimum distance to the border to determine the ring
                int ring = min(min(i, 9 - i), min(j, 9 - j));
                points += ringPoints[ring];
            }
        }
    }

    return points;
}

int main() {
    int t;
    cin >> t;

    vector<int> results(t);

    for (int k = 0; k < t; ++k) {
        vector<string> grid(10);
        for (int i = 0; i < 10; ++i) {
            cin >> grid[i];
        }
        results[k] = calculatePoints(grid);
    }

    for (int result : results) {
        cout << result << endl;
    }

    return 0;
}
