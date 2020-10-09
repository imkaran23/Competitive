class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
        long long x = 1;
        while(x<n){
            x = x<<1;
            if(x==n) return true;
        }
        return false;
    }
};