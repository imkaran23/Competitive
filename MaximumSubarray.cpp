class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int n = v.size();
        int dp[n];
        dp[0] = v[0];
        for(int i=1; i<n; i++){
            dp[i] = max(dp[i-1]+v[i],v[i]);
        }
        int ans = INT_MIN;
        for(int i=0; i<n; i++) ans = max(ans,dp[i]);
        
        return ans;
    }
};

// class Solution {
//     public : 
//     int maxSubArray(vector<int>& nums) {
//         int max=INT_MIN,sum=0,i,size=nums.size();
//         for(i=0;i<size;i++){
//             sum+=nums[i];
//             if(max<sum)
//                 max=sum;
//             if(sum<0)
//                 sum=0;
//         }
//         return max;
//     }
// };