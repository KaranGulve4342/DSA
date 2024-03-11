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
