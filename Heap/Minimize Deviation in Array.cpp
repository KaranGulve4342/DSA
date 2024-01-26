// LEETCODE 1675

#include<bits/stdc++.h>
using namespace std;

class Solution{
public:
    int minimumDeviation(vector<int> &a){
        priority_queue<int> pq;

        int mini = 1e9;
        int result = 1e9;

        for(auto x : a){
            if(x % 2 != 0){
                x *= 2;
            }
            pq.push(x);
            mini = min(mini, x);
        }

        while(true){
            int val = pq.top();
            pq.pop();

            result = min(result, val - mini);
            if(val % 2 != 0){
                break;
            }
            mini = min(mini, val/2);
            pq.push(val/2);
        }

        return result;
    }
}