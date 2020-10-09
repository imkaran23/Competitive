class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        if(nums.size()==2) return max(nums[0],nums[1]);
        if(nums.size()==3) return max(nums[0],max(nums[1],nums[2]));
        vector<int> dp = nums;
        nums[1] = max(nums[0],nums[1]);
        for(int i=2; i<nums.size()-1; i++) nums[i] = max(nums[i]+nums[i-2], nums[i-1]);
        dp[2] = max(dp[2],dp[1]);
        for(int i=3; i<dp.size(); i++) dp[i] = max(dp[i]+dp[i-2], dp[i-1]);
        return max(dp[dp.size()-1], nums[nums.size()-2]);
    }
};

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         if(nums.size()==0) return 0;
//         if(nums.size()==1) return nums[0];
//         if(nums.size()==2) return max(nums[0],nums[1]);
//         if(nums.size()==3) return max(nums[0],max(nums[1],nums[2]));
        
//         return max( solve(nums, 0, nums.size()-1), solve(nums, 1, nums.size()));
//     }
    
//     int solve(vector<int> nums, int low, int high){
//         nums[low+1] = max(nums[low],nums[low+1]);
//         for(int i=low+2; i<high; i++) nums[i] = max(nums[i]+nums[i-2], nums[i-1]);
//         return nums[high-1];
//     }
// };

// class Solution {
// public:
//     int rob(vector<int>& nums) {
//         int n = nums.size(); 
//         if (n < 2) return n ? nums[0] : 0;
//         return max(robber(nums, 0, n - 2), robber(nums, 1, n - 1));
//     }
// private:
//     int robber(vector<int>& nums, int l, int r) {
//         int pre = 0, cur = 0;
//         for (int i = l; i <= r; i++) {
//             int temp = max(pre + nums[i], cur);
//             pre = cur;
//             cur = temp;
//         }
//         return cur;
//     }
// };

