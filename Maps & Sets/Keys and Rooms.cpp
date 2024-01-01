// LEETCODE 841

/*
class Solution {
public:
    void dfs(vector<vector<int>> rooms, int room, unordered_set<int> &visited){
        visited.insert(room); // mark the current room as visited
        
        for(int key : rooms[room]){
            if(visited.find(key) == visited.end()){
                dfs(rooms,key,visited); // visit the adjacent rooms recursively
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();

        unordered_set<int> visited;

        dfs(rooms,0,visited); // start with room zero

        return n == visited.size();
    }
};
*/