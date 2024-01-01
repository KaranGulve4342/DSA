#include <iostream>
using namespace std;

int main()
{
    int arr[6] = {0,0,0,0,1,1};
    int n = 6;

    int start = 0;
    int end = n-1;

    

    while(start <= end){
        int mid = start + (end - start)/2;

        if(arr[mid] == 1){
            end = mid - 1;
        }
        else start = mid + 1;
    }
    cout<<n-start;
    
    return 0;
}