class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1) return nums.size(); 
        vector<int> dp(nums.size(),1);
        int ans = 1;
        for (int i = 1; i < nums.size(); i++) {
            int x = 0;
            for (int j = 0; j < i; j++){
                if(nums[i]>nums[j]){
                    x = max(dp[j],x);
                }
                dp[i] = 1 + x;
                ans = max(ans, dp[i]);
            }
        }
        return ans;
    }
    
//     int lengthOfLIS(vector<int>& nums) {
//         if (nums.size() == 0)
//             return nums.size();

//         vector<int>::iterator m = nums.begin();
//         for (int& val : nums) {
//             auto it = lower_bound(nums.begin(), m, val);
//             *it = val;
//             if (it == m)
//                 m++;
//         }
//         return m - nums.begin();
//     }
};