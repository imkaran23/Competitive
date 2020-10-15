class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if(nums.size()<2) return 0;
        if(nums.size()==2) return nums[0]>nums[1]?0:1;
        int lo = 0, hi = nums.size()-1;
        
        while(lo<hi){
            int mid = lo + (hi-lo)/2;
            if(nums[mid] < nums[mid+1]) lo = mid+1;
            else hi = mid;
        }       
        return lo;
    }
};