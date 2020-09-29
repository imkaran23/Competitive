class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.length()+s2.length()!=s3.length()) return false;
        bool dp[s2.length()+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=0;i<=s1.length();i++)
            for(int j=0;j<=s2.length();j++){
                if(i==0 && j==0) dp[j]=1;
                else if(i==0) dp[j]=(s2[j-1]==s3[j-1] && dp[j-1]);
                else if(j==0) dp[j]=(s1[i-1]==s3[i-1] && dp[j]);
                else dp[j]=((s1[i-1]==s3[i+j-1] && dp[j]) || (s2[j-1]==s3[i+j-1] && dp[j-1]));
            }
        return dp[s2.length()];
    }
};

// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         int a = s1.size(), b = s2.size(), c = s3.size();
//         if(a+b != c) return false;
//         int dp[a+1][b+1];
//         dp[0][0] = true;
//         for (int i = 1; i <= a; ++i) dp[i][0] = dp[i - 1][0] && (s1[i - 1] == s3[i - 1]);
//         for (int j = 1; j <= b; ++j) dp[0][j] = dp[0][j - 1] && (s2[j - 1] == s3[j - 1]);
//         for(int i=1; i<=a; i++) for(int j=1; j<=b;j++) dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1] ) || (dp[i][j-1] && s2[j-1]==s3[i+j-1] );
//         return dp[a][b];
//     }
// };