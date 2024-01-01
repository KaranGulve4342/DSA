// LEETCODE 881

/*
TC = O(n.log(n))
SC = O(sorting algo)

class Solution{
public:
    int numRescueBoats(vector<int>& people, int limit){
        sort(people.begin(), people.end());
        int i = 0, j=  people.size() - 1;
        int bt = 0;
        while(i <= j){
            if(people[i] + people[j] <= limit){
                bt++; // allocate a boat to the pair
                i++;
                j--;
            }
            else{
                bt++;
                j--; // allocatea boat ot the heaviest
            }
        }
        return bt;
    }
}
*/