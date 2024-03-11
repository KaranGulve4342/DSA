// LEETCODE 791

class Solution {
public:
    static string Order;
    static bool customSort(char a, char b) {
        return (Order.find(a) < Order.find(b));
    }
    
    string customSortString(string order, string s) {
        Order = order;
        sort(s.begin(), s.end(), customSort);
        return s;
    }
};

string Solution::Order = ""; // Definition of static member variable


// METHOD 2

class Solution {
public:
    static map<char, int> mp;
    static bool comparator(char &a, char &b){
        if(mp[a] < mp[b]){
            return true;
        }
        else return false;
    }
    string customSortString(string order, string s) {
        for(int i = 0;i < order.length();i++)`{
            mp[order[i]] = i;
        }
        sort(s.begin(), s.end(), comparator);
        return s;
    }
};

map<char, int> Solution::mp = {};