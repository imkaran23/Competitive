class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp (n, vector <bool> (n, false));
        vector<vector<string>> ans;
        vector<string> tmp;
        bt(ans, s, 0, tmp, dp, n);
        return ans;
    }
    
    void bt(vector<vector<string>> &ans, string &s, int start, vector<string> &tmp, vector<vector<bool>> &dp, int &n){
        if(start>=n) ans.push_back(tmp);
        for(int i=start; i<n; i++){
            if(s[start]==s[i] && (i-start<=2 || dp[start+1][i-1])){
                dp[start][i] = true;
                tmp.push_back(s.substr(start, i - start + 1));
                bt(ans, s, i+1, tmp, dp, n);
                tmp.pop_back();
            }
        }
    }
};