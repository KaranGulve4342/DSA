// Given an integer n, find the maximum power of two which is smaller than n.
/*
#include<iostream>
using namespace std;

int max_power_of2(int n){
    n = n | (n >> 1);
    n = n | (n >> 2);
    n = n | (n >> 4);
    n = n | (n >> 8);
    n = n | (n >> 16);
    return (n+1)>>1;
}
int main(){

    int x = 90;
    int temp;
    while(x != 0){
        temp = x;
        x = x & (x - 1);
    }
    cout<<temp<<"\n";
    cout<<max_power_of2(90)<<endl;

    return 0;
}
*/

// Given an integer n,flip all its bits i.e. if the given bit is 1, change it to 0 and vice versa
/*
#include<iostream>
using namespace std;

int main(){

    int x = 34;
    int temp;
    while(x != 0){
        temp = x;
        x = x & (x - 1);
    }
    cout<<temp<<"\n";
    int n = 2*temp - 1;
    cout<< (34 ^ n);
    return 0;
}
*/

// Calculate the minimum number of bit flips to ci=onvert from one number to another.

// Given an integer array where every element occurs twice except one occurs only once. Find the unique element.

/*
#include<iostream>
using namespace std;

int main(){
    int arr[] = {1,2,3,4,5,4,1,2,3};
    int n = 9;
    int res = 0;

    for(int i = 0;i < n;i++){
        res = res ^ arr[i];
    }
    cout<<res<<"\n";
    return 0;
}
*/

// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. find the two elements that appear only once
/*
#include <iostream>
using namespace std;

void findUnique(int *arr, int n)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res = res ^ arr[i];
    int temp = res;
    int k = 0;
    while (true)
    {
        if ((temp & 1) == 1)
        {
            break;
        }
        temp = temp >> 1;
        k++;
    }
    int retval = 0;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        if (((num >> k) & 1) == 1)
            retval ^= num;
    }
    cout << retval << " ";
    res = retval ^ res;
    cout << res << " ";
}

int main()
{
    int arr[] = {1, 2, 1, 3, 2, 5};
    int n = 6;
    findUnique(arr, n);
    return 0;
}
*/

// Given an integer array. Find the length of longest subarray which has maximum possible bitwise AND value.

// #include<iostream>
// using namespace std;

// int main(){
//     int arr[] = {12,3,1,6,1,6,18,6,6,6,4,3,8,13,13,13,8};
//     int n = 17;
//     int ans = 0;
//     int max_el = INT_MIN;
//     int count = 0;
//     for(int i = 0;i < n;i++){
//         if(arr[i] > max_el){
//             max_el = arr[i];
//             count = 1;
//         }
//         else if(arr[i] == max_el){
//             count++;
//         }
//         ans = max(ans,count);
//     }
//     cout<<ans<<"\n";
//     return 0;
// }

