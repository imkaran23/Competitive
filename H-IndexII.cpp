class Solution {
public:
    int hIndex(vector<int>& citations) {
        int lo = 0, hi = citations.size()-1, n = citations.size(), ans=0;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(citations[mid]>=n-mid){
                ans = n-mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};