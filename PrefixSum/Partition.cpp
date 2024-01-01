#include<iostream>
using namesapce std;

int main(){
    it arr[]=  {1,2,3,4,5,5,10,10};
    int n = sizeof(arr)/size(arr[0]);
    // formation of prefix sum
    for(int i =  1;i < n;i++){
        arr[i] += arr[i-1];
    }
    // check if any x exists
    int idx = -1;
    for(int i = 1;i < n;i++{
        if(2*arr[i] == arr[n-1]){
            idx = i;
            break;
        }
    }
    if(idx != -1) cout<<"Yes it can be patitioned after"<<idx;
    else cout<<" cannot be partitioned"
}