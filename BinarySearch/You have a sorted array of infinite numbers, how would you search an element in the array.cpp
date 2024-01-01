#include <iostream>
using namespace std;

int main()
{
    int a[] = {1,2,4,7,10,12,15,18};
    int lo = 0;
    int hi = 1;
    int target = 10;
    while(a[hi] < target){
        hi *= 2;
    }
    cout<<lo<<" "<<hi<<endl;
    bool flag = false;
    while(lo <= hi){
        int mid = lo + (hi - lo)/2;
        if(a[mid] == target){
            flag = true;
            break;
        }
        else if(a[mid] > target){
            hi = mid - 1;
        }
        else lo = mid + 1;
    }
    if(flag == true) cout<<"Element Exists"<<endl;
    return 0;
}