class NumArray {
    vector<int> dp;
public:
    NumArray(vector<int>& nums) {
        dp.resize(nums.size()+1,0);
        for(int i=1; i<=nums.size(); i++){
            dp[i] = dp[i-1] + nums[i-1];
        }
    }
    
    int sumRange(int i, int j) {
        return dp[j+1]-dp[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */