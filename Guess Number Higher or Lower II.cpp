class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,0));
        return recur(dp,1,n);
    }
    
    int recur(vector<vector<int>>& dp, int s, int e){
        if(s>=e) return 0;
        if(dp[s][e]!=0) return dp[s][e];
        int ans = INT_MAX;
        for(int i = s; i<=e; i++)
            ans = min(ans, i + max(recur(dp,s,i-1), recur(dp,i+1,e)));
        
        dp[s][e] = ans;
        return ans;
    }
};

// class Solution {
// public:
//     int getMoneyAmount(int n) {
//         vector<vector<int>> dp(n+1, vector<int>(n+1,0));
//         for(int j=2; j<=n; j++){
//             for(int i=j-1; i>0; i--){
//                 int globalMin = INT_MAX;
//                 for(int k=i+1; k<j; k++){
//                     globalMin = min(globalMin, k + max(dp[i][k-1], dp[k+1][j]));
//                 }
//                 dp[i][j] = i+1==j?i:globalMin;
//             }
//         }
//         return dp[1][n];
//     }
// };