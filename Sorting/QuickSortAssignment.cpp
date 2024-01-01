// Given an array where all its elements are sorted in increasing order except two swapped elements, sort it in linear time. Assume there are no duplicates in the array.

#include<iostream>
#include<vector>
using namespace std;

int partition(vector<int>& arr, int low, int high){
    int pivot = arr[high];
    int i = low - 1;

    for(int j = low;j < high;j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i],arr[high]);

    return i; // pivotIndex
}

void quickSort(vector<int>& arr,int low, int high){
    if(low < high){
        int pivotIndex = partition(arr,low,high);

        quickSort(arr, low, pivotIndex-1);
        quickSort(arr, pivotIndex + 1,high);
    }
}

void sortSwappedArray(vector<int>& arr){
    int n=  arr.size();

    // find the two swapped elements
    int first = -1;
    int second = -1;
    for(int i = 0;i < n-1; i++){
        if(arr[i] > arr[i+1]){
            if(first == -1){
                first = i;
            }
            else{
                second = i + 1;
                break;
            }
        }
    }
    // swap the two elements
    swap(arr[first],arr[second]);

    // Perform quicksort only on the subarray between the swapped elements
    quickSort(arr, min(first,second), max(first,second));
}

int main(){
    vector<int> arr = {3,8,6,7,5,9,10};

    for(int num : arr){
        cout<<num<<" ";
    }
    cout<<endl;

    sortSwappedArray(arr);

    for(int k : arr){
        cout<<k<<" ";
    }
    cout<<endl;
    return 0;
}