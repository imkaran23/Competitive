class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        int ans = nums[0], mini = nums[0], maxi=nums[0];
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<0) swap(maxi,mini);
            maxi = max(maxi*nums[i], nums[i]);
            mini = min(mini*nums[i], nums[i]);
            ans = max(ans,maxi);
        }
        return ans;
    }
};