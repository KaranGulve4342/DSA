#include<iostream>
#include<vector>

using namespace std;

void merge(vector<int> &a, vector<int> &b, vector<int> &res){
    int i = 0;
    int j = 0;
    int k = 0;

    while(i < a.size() && j < b.size()){
        if(a[i] < b[j]){
            res[k++] = a[i++];
        }
        else{
            res[k++] = b[j++];
        }
    }
    if(i == a.size()){
        while(j < b.size()){
            res[k++] = b[j++];
        }
    }
}

void mergeSort(vector<int> &v)
{
    int n = v.size();
    if(n == 1) return;
    int n1 = n/2, n2 = n - n/2;
    vector<int> a(n1),b(n2);
    // copy pasting
    for(int i = 0;i < n1;i++)
    {
        a[i] = v[i];
    }
    for(int i = 0;i < n2;i++)
    {
        b[i] = v[i + n1];
    }
    // magic aka recursion
    mergeSort(a);
    mergeSort(b);

    // merge
    merge(a, b, v);
}

int main()
{
    int arr[] = {8,4,484,874,85,84,57,489,478,0,480,0,4080804,56,};
    int n = sizeof(arr)/sizeof(arr[0]);

    vector<int> v(arr,arr+n); // same as arr, copy
    for(int i = 0;i < v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;

    mergeSort(v);
    for(int i= 0;i < v.size();i++)
    {
        cout<<v[i]<<" ";
    }
}