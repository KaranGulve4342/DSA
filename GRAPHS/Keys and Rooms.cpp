// LEETCODE 841

/*
class Solution{
public:
    void dfs(vector<vector<int> >&rooms, int room, unordered_set<int> &visited){
        visited.insert(room);

        for(auto key : rooms[room]){
            if(visited.find(key) == visited.end()){
                dfs(rooms, key, visited);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int> >&rooms){
        int n = rooms.size();

        unordered_set<int> visited;

        dfs(roomes, 0, visited);

        return n == visited.size();
    }
}
*/

/*
class Solution{
public:
    bool canVisitAllRooms(vector<vector<int> >& rooms){
        unordered_set<int> visited;
        queue<int> qu;
        qu.push(0);
        visited.insert(0);
        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();
            for(int neighbour : rooms[curr]){
                if(visited.count(neighbour) == 0){
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
        return visited.size() == rooms.size();
    }
};
*/

/*

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int> >&rooms){
        unordered_set<int> visited;
        queue<int> qu;
        qu.push(0);
        visited.insert(0);

        while(!qu.empty()){
            int curr = qu.front();
            qu.pop();
            for(int neighbour: rooms[curr]) {
                if(visited.count(neighbour) == 0){
                    // neighbour not yet visited
                    qu.push(neighbour);
                    visited.insert(neighbour);
                }
            }
        }
    }
    return visited.size() == roomes.size();
}

*/