class Solution {
public:
    int numSquares(int n) {
        if(n<4) return n;
        vector<int> dp(n+1,INT_MAX);
        dp[0] = 0, dp[1] = 1, dp[2] = 2, dp[3] = 3;
        for(int i=4; i<=n; i++)
            for(int j=1; j*j<=i; j++)
                dp[i] = min(dp[i], dp[i-j*j]+1);
        
        return dp[n];
        
//         static vector<int> cntPerfectSquares({0});
//         while (cntPerfectSquares.size() <= n){
//             int m = cntPerfectSquares.size();
//             int cntSquares = INT_MAX;
//             for (int i = 1; i*i <= m; i++)
//                 cntSquares = min(cntSquares, cntPerfectSquares[m - i*i] + 1);
            
//             cntPerfectSquares.push_back(cntSquares);
//         }
        
//         return cntPerfectSquares[n];
    }
};