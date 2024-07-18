#include<bits/stdc++.h>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[high]);

    return i; // pivotIndex
}

void quickSort(vector<int>& arr, int low, int high){
    if(low < high){
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

void sortSwappedArray(vector<int>& arr){
    int n = arr.size();

    // Check if the array is already sorted
    bool isSorted = true;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            isSorted = false;
            break;
        }
    }
    if (isSorted) {
        return;
    }

    // Find the two swapped elements
    int first = -1, second = -1;
    for(int i = 0; i < n - 1; i++){
        if(arr[i] > arr[i + 1]){
            if(first == -1){
                first = i;
                second = i + 1; // Assume the next element is the second until found otherwise
            } else {
                second = i + 1;
            }
        }
    }

    // Swap the two elements
    swap(arr[first], arr[second]);

    // Perform quicksort on the entire array to ensure it is sorted
    quickSort(arr, 0, n - 1);
}

int main(){
    vector<int> arr = {23, 21, 89, 9, 76, 1, 65, 77, 99, 14357906, 1045};

    sortSwappedArray(arr);

    for(int k : arr){
        cout << k << " ";
    }
    cout << endl;
    return 0;
}