#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>&arr, int start,int mid, int end){
    int n1 = mid - start + 1;
    int n2 = end - mid;

    vector<int> a(n1);
    vector<int> b(n2);

    for(int i = 0;i < n1;i++){
        a[i] = arr[start + i];
    }
    for(int j = 0;j < n2;j++){
        b[j] = arr[mid+1+j];
    }

    int i = 0;
    int j = 0;
    int k = start;

    while(i < n1 && j < n2){
        if(a[i] > b[j]){
            arr[k] = a[i];
            i++;
            k++;
        }
        else{
            arr[k] = b[j];
            j++;
            k++;
        }
    }

    while(i < n1){
        arr[k] = a[i];
        i++;
        k++;

    }
    while( j < n2){
        arr[k] = b[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& arr,int start,int end){
    if(start<end){
        int mid = start + (end - start)/2;

        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);

        merge(arr,start,mid,end);
    }
}

void descendingMergeSort(vector<int> &arr){
    int n = arr.size();
    mergeSort(arr,0,n-1);
}

int main(){
    vector<int> nums = {9,2,5,3,7,9,0,8,5,2,1,6,59,999};
    descendingMergeSort(nums);

    for(int num : nums){
        cout<<num<<" ";
    }
    return 0;
}
