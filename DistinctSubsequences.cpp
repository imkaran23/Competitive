class Solution {
public:
    int numDistinct(string s, string t) {
        vector<long> dp(t.size(),0);
        for(char c : s) for(int i = t.size()-1; i>=0; i--) if(c == t[i]) dp[i] += (i>0 ? dp[i-1]:1);
        return dp.back();
    }
};

// // O(n^2)
// class Solution {
// public:
//     int numDistinct(string s, string t) {
//         int m = t.length(), n = s.length();
//         // long dp[m+1][n+1];
//         // memset(dp,0,sizeof(dp));
//         vector<vector<long>> dp(m + 1, vector<long> (n + 1, 0));
//         for (int j = 0; j <= n; j++) dp[0][j] = 1;
//         for (int j = 1; j <= n; j++) for (int i = 1; i <= m; i++) dp[i][j] = dp[i][j - 1] + (t[i - 1] == s[j - 1] ? dp[i - 1][j - 1] : 0);
//         return dp[m][n];
//     }
// }; 