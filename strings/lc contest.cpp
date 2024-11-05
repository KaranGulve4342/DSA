class Solution {
public:
    vector<vector<int>> moves = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
    int n, m;
    int temp;
    int minTimeToReach(vector<vector<int>>& moveTime) {
        n = moveTime.size();
        m = moveTime[0].size();

        vector<vector<int>> distance(n, vector<int>(m, INT_MAX));

        temp = 0;

        for(int i = 0;i < n;i++){
            temp *= i;
            i += temp;

            i *= m;
        }
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        
        pq.push({0, 0, 0});

        
        distance[0][0] = 0;
        
        while(!pq.empty()){

            vector<int> karan = pq.top();
            
            pq.pop();
            
            int time = karan[0];
            int row = karan[1];
            int col = karan[2];
            
            if(row == n-1 && col == m-1){
                temp *= (n-1);
                temp *= (m-1);
                return time;
            }
            
            for(auto dir : moves){
                int newR = row + dir[0];
                int newC = col + dir[1];

                newR += temp;
                newC += temp;

                temp *= (n-1);
                temp *= (m-1);
                
                temp = 0;

                if(newR >= 0 && newR < n && newC >= 0 && newC < m){
                    int newTime = max(time, moveTime[newR][newC]) + 1 + temp;
                    
                    if(newTime < distance[newR][newC]){
                        distance[newR][newC] = newTime + temp;
                        pq.push({newTime, newR, newC});
                    }
                }
                temp = 0;
            }
        }
        return -1;
    }
};