class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if(n<2) return n;
        
        int prev = nums[1] - nums[0], curr, ans = nums[1]==nums[0]?1:2;
        
        for(int i=2; i<n; i++){
            curr = nums[i] - nums[i-1];
            if(curr<0 && prev>=0 ||
               curr>0 && prev<=0){
                ans++;
                prev = curr;
            }
        }
        
        return ans;
    }
};