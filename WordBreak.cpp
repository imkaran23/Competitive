class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n+1, false);
        dp[0] = true;
        for(int i=1; i<=n; i++){
            // for(int j=0; j<i; j++){
            //     if( dp[j] && st.find(s.substr(j,i-j))!=st.end()){
            //         dp[i] = true;
            //         break;
            //     }
            // }
            for(int j=i-1; j>=0; j--){
                if( dp[j] && st.find(s.substr(j,i-j))!=st.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

// class Solution {
// public:
//     unordered_map<string, bool> mp;
//     bool wordBreak(string s, vector<string>& wordDict) {
//         unordered_set<string> st(wordDict.begin(), wordDict.end());
//         return recur(s, st);
//     }
    
//     bool recur(string s, unordered_set<string> st){
//         if(st.find(s)!=st.end()) return true;
//         if(mp.find(s)!=mp.end()) return mp[s];
//         for(int i=1; i<=s.size(); i++){
//             if(st.find(s.substr(0,i))!=st.end()  && recur(s.substr(i), st)){
//                 mp[s] = true;
//                 return true;
//             }
//         }
//         mp[s] = false;
//         return false;
//     }
// };