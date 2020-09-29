class Solution {
public:
    int numDecodings(string s) {
        if(s[0]=='0') return 0;
        int n = s.size();
        vector<int> dp(n+1);
        dp[0] = dp[1] = 1;
        
        for(int i=1; i<n; i++){ 
            int x = s[i]-'0';
            int y = s[i]-'0' + 10*(s[i-1]-'0');
            
            if(x>=1) dp[i+1] += dp[i];
            if(y>=10 && y<=26) dp[i+1] += dp[i-1];
        }
        return dp[n];
    }
};