class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT_MAX, sum=0, l=0, r=0;
        while(r<nums.size()){
            sum += nums[r++]; 
            while(sum>=s){ 
                ans = min(ans,r-l);
                sum -= nums[l++];
            }
        }
        return ans==INT_MAX?0:ans;
    }
};

// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         int n = nums.size(), ans = INT_MAX;
//         vector<int> sums(n + 1, 0);
//         for (int i = 1; i <= n; i++) sums[i] = sums[i - 1] + nums[i - 1];
//         for (int i = n; i >= 0 && sums[i] >= s; i--) {
//             int j = upper_bound(sums.begin(), sums.end(), sums[i] - s) - sums.begin();
//             ans = min(ans, i - j + 1);
//         }
//         return ans == INT_MAX ? 0 : ans;
//     }
// };