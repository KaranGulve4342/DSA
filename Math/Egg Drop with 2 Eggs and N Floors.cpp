// LEETCODE 1884

class Solution {
public:
    int twoEggDrop(int n) {
        // as we know x + (x-1) + (x-2) + (x-3) + ..... >= n
        // i.e. x*(x+1)/2 >= n;
        // x^2 + x - 2n >= 0;

        // solving above quadratic Equation
        int a = 1;
        int b = 1;
        int c = -2*n;

        // Therefore, x = (-b + sqrt(b*b - 4*a*c))/2*a

        int ans = (int)ceil((-1*b + sqrt(b*b - 4*a*(c)))/2*a);
        return ans;
    }
};~