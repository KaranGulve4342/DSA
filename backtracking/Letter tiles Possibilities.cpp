// LEETCODE 1079

class Solution {
    public:
        int result;
        void solve(string tiles, int begin){
            result++;
    
            for(int i = begin;i < tiles.length();i++){
                if(i != begin && tiles[i] == tiles[begin]){
                    continue;
                }
                swap(tiles[i], tiles[begin]);
    
                solve(tiles, begin + 1);
            }
        }
        int numTilePossibilities(string tiles) {
            sort(tiles.begin(), tiles.end());
    
            result = -1;
    
            solve(tiles, 0);
    
            return result;
        }
    };