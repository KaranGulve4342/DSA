#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

void sum(vector<int>& arr, int k){
    int n = arr.size();
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n-2; i++){
        while(i > 0 and arr[i] == arr[i-1]) continue;
        int left = i+1;
        int right = n-1;

        while(left < right){
            int sum = arr[i] + arr[left] + arr[right];
            if(sum == k){
                cout << arr[i] << " " << arr[left] << " " << arr[right] << endl;
                left++;
                right--;
                while(left<right && arr[left] == arr[left-1]) left++;
                while(left<right && arr[right] == arr[right+1]) right--;
            }
            else if(sum < k){
                left++;
            }
            else{
                right--;
            }
        }
    }
}

int main(){
    vector<int> arr= {1,2,-1,0,-2,1,1,-1,-1,-2,1,0,3,-4,-3};
    
    sum(arr, -1);
    return 0;
}
