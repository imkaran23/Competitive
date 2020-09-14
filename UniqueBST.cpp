class Solution {
public:
    int numTrees(int n) {
    vector<int> dp(n+1,0);
    dp[0]= 1;
    dp[1] = 1;
    for(int level = 2; level <=n; level++)
        for(int root = 1; root<=level; root++)
            dp[level] += dp[level-root]*dp[root-1];
    return dp[n];
    }
};