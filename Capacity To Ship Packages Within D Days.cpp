class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int lo=1, hi = 25000000;
        for (int w: weights) lo = max(lo, w);
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(!check(weights, mid, D)) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    }
    
    bool check(vector<int>& weights, int& mid, int& D){
        int d = 1, i=0, sum=0, n = weights.size();       
        while(i<n){
            if(sum+weights[i]<=mid){
                sum += weights[i];
                i++;
            }
            else{
                d++;
                if(d > D) return false;
                sum=0;
            };
        }
        
        return true;
    }
};