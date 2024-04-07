// LEETCODE 678

class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open;
        stack<int> star;

        for(int i = 0;i < s.length();i++){
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else{
                if(!open.empty()){
                    open.pop();
                }
                else if(!star.empty()){
                    star.pop();
                }
                else{
                    return false;
                }
            }
        }
        while(!open.empty() && !star.empty() && star.top() > open.top()){
            open.pop();
            star.pop();
        }

        return open.empty();
    }
};

#include <iostream>
#include <vector>

const int MOD = 1000000007;

int countPairs(int n) {
    std::vector<int> factorial(n + 1, 1);
    for (int i = 2; i <= n; i++) {
        factorial[i] = (factorial[i - 1] * i) % MOD;
    }

    int count = 0;
    for (int x = 1; x <= n; x++) {
        if (factorial[x] > n) {
            break;
        }
        if ((n * factorial[x]) % (factorial[x] - n) == 0) {
            count++;
        }
    }

    return count;
}

int main() {
    int n;
    std::cout << "Enter the value of n: ";
    std::cin >> n;

    int result = countPairs(n);
    std::cout << "Number of pairs: " << result << std::endl;

    return 0;
}