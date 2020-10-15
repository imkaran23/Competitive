class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = 1, hi = num/2+1;
        while(lo<=hi){
            long long mid = lo + (hi-lo)/2;
            if(mid*mid == num) return true;
            if(mid*mid > num) hi = mid-1;
            else lo = mid+1;
        }
        return false;
    }
};