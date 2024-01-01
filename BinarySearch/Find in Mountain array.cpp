// LEETCODE 1095 
// HARD


/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int start = 0;
        int end = mountainArr.length() - 1;
        int mid;

        while(start < end){
            int mid = start + (end - start)/2;
            if(mountainArr.get(mid) < mountainArr.get(mid+1)) start = mid + 1;
            else end = mid;

        }

        // first_Half
        int peak = start;
        start =  0;
        end = peak;
        bool first_Half = false;
        bool second_Half = false;
        while(start <= end){
            mid = start + (end - start)/2;
            if(mountainArr.get(mid) == target){
                first_Half = true;
                break;
            }
            else if(mountainArr.get(mid) < target){
                start = mid + 1;
            }
            else end = mid - 1;
        }
        if(first_Half == true) return mid;

        // second_half
        start = peak + 1;
        end = mountainArr.length() - 1;

        while(start <= end){
            mid = start + (end - start)/2;
            if(mountainArr.get(mid) == target){
                second_Half = true;
                break;
            }
            else if(mountainArr.get(mid) > target){
                start = mid + 1;
            }
            else end = mid - 1;
        }
        if(second_Half == true) return mid;

        return -1;
    }
};

int main()
{
    
    
    return 0;
}