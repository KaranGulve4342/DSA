// LEETCODE 50

class Solution{
public:
    double myPow(double x, int n){
        if(n == 0) return 1;
        if(n < 0) return myPow(x, -(n+1));

        double temp = myPow(x, n/2);
        return (n%2 == 0) ? temp*temp : temp*temp*x;
    }
}