class Solution {
public:
    int coinChange(vector<int>& coins, int n) {
        vector<int> dp(n+1,n+1);
        dp[0] = 0;
        for(int c : coins)
            for(int i=c; i<=n; i++)
                if (i-c>=0) 
                    dp[i] = min(dp[i], dp[i-c]+1);
        
        return dp[n]>n?-1:dp[n];
    }
};