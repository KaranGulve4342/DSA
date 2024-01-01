#include<iostream>
using namespace std;

int partition(int arr[], int si, int ei) {
    int pivotElement = arr[si + (ei - si) / 2];
    int count = si;
    
    // Move the pivot to the end
    swap(arr[si + (ei - si) / 2], arr[ei]);

    for (int i = si; i < ei; i++) {
        if (arr[i] <= pivotElement) {
            swap(arr[i], arr[count]);
            count++;
        }
    }

    swap(arr[count], arr[ei]); // Move pivot to its final place
    return count;
}

int kthSmallest(int arr[], int si, int ei, int k) {
    if (k > 0 && k <= ei - si + 1) {
        int pi = partition(arr, si, ei);

        if (pi - si == k - 1)
            return arr[pi];
        else if (pi - si > k - 1)
            return kthSmallest(arr, si, pi - 1, k);
        else
            return kthSmallest(arr, pi + 1, ei, k - (pi - si) - 1);
    }
    return -1; // Invalid input
}

int main() {
    int arr[] = {5, 1, 8, 20, 7, 6, 3, 4, -8};
    int n = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    int k = 4;
    cout << "Kth smallest element: " << kthSmallest(arr, 0, n - 1, k) << endl;
}
