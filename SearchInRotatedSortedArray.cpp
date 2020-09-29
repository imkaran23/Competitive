class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int mid, lo=0, hi=n-1;
        while(lo<hi){
            mid = lo + (hi-lo)/2;
            if(nums[mid]>nums[hi]) lo=mid+1;
            else hi=mid;
        }
        int start = lo;
        lo=0, hi=n-1;
        while(lo<=hi){
            mid = lo + (hi-lo)/2;
            int mid_new = (mid+start)%n;
            if(nums[mid_new]==target) return mid_new;
            else if(nums[mid_new]>target) hi = mid-1;
            else lo = mid+1;
        }
        return -1;
    }
};