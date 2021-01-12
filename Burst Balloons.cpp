class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr = {1};
        for(auto& num : nums)
            if(num) arr.push_back(num);
        arr.push_back(1);
        int len = arr.size();
        
        vector<vector<int>> dp(len, vector<int>(len, 0));
        
        for(int gap = 2; gap < len; gap++) {
            for(int left = 0; left < len-gap; left++) {
                int right = left+gap;
                for(int mid = left+1; mid < right; mid++) 
                    dp[left][right] = max( dp[left][right], dp[left][mid]+dp[mid][right]+arr[left]*arr[mid]*arr[right]);
            }
        }
        return dp[0][len-1];
    }
};
//IO
int _IO=[](){
	ios::sync_with_stdio(0);
	cin.tie(0); //cout.tie(0);
	return 0;
}();