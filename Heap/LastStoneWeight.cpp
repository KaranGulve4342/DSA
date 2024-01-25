// LEETCODE 1046

/*
class Solution{
public:
    int lastStoneWeight(vector<int>& stones){
        priority_queue<int> pq(stones.begin(), stones.end());
        while(pq.size() > 1){
            int p1 = pq.top(); // max element
            pq.pop();
            int p2 = pq.top(); // 2nd Max element
            pq.pop();

            int diff=  abs(p1 - p2);
            if(diff != 0) pq.push(diff);
        }
        if(pq.size() == 0) return 0;
        return pq.top();
    }
};
*/

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int lastStoneWeight(vector<int>& arr){
        priority_queue<int> pq;
        for(int ele : arr){
            pq.push(ele);
        }

        while(pq.size() > 1){
            int x = pq.top();
            pq.pop();

            int y = pq.top();
            pq.pop();

            if(x != y){
                pq.push(x - y);
            }
        }


        if(pq.size() == 1) return pq.top();
        return 0;
    }
};