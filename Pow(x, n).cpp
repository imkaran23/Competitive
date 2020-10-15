class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1;
        long N = abs((long)n);
        while(N > 0) {
            if((N&1)==1) ans *= x;
            N >>= 1;
            x *= x;
        }
        return n < 0 ?  1/ans : ans;
    }
};