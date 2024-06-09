// LEETCODE 3176

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {
        int n = skills.size();
        deque<int> players;
        int ans = 0;

        if(k >= n){
            // int maxi *max_element(skills.begin(), skills.end());
            int maxIdx = 0;
            int maxi = skills[0];
            for(int i = 1;i < n;i++){
                if(skills[i] > maxi){
                    maxi = skills[i];
                    maxIdx = i;
                }
            }

            return maxIdx;
        }

        for(int i = 0;i < n;i++){
            players.push_back(i);
        }

        int curr_winner = players.front();
        players.pop_front();

        while(ans < k){
            int opponent = players.front();
            players.pop_front();

            if(skills[curr_winner] <= skills[opponent]){
                ans = 1;
                players.push_back(curr_winner);
                curr_winner = opponent;
            }
            else{
                ans++;
                players.push_back(opponent);
            }
        }

        return curr_winner;
    }
};