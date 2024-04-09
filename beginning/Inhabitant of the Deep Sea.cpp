/*
t = int(input())
for _ in range(t):
    n, k = map(int, input().split())
    durability = list(map(int, input().split()))

    ## calculate the number of ships sunk
    sunk = 0
    left = 0
    
    while k > 0 and left <= right:
        if durability[left] == 0:
            left += 1
        elif durability[right] == 0:
            right -= 1
        else:
            if left == right:
                sunk += 1
            else:
                sunk += 2
            k-=1
            if durability[left] < durability[right]:
                right -= 1
            else:
                left += 1
    print(sunk)

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> durability(n);
        for (int i = 0; i < n; ++i) {
            cin >> durability[i];
        }

        int sunk = 0;
        int left = 0;
        int right = n - 1;

        while (k > 0 && left <= right) {
            if (durability[left] == 0) {
                left++;
            } else if (durability[right] == 0) {
                right--;
            } else {
                if (left == right) {
                    sunk+=1;
                } else {
                    sunk += 2;
                }
                k-=1;

                if (durability[left] < durability[right]) {
                    right-=1;
                } else {
                    left+=1;
                }
            }
        }
        cout << sunk << endl;
    }
    return 0;
}
