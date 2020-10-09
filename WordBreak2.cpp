class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        unordered_map<string, vector<string>> mp;
        return recur(s, st, mp);
    }
    
    vector<string> recur(string s, unordered_set<string>& st, unordered_map<string, vector<string>>& mp){
        cout<<s<<" ";
        if(mp.count(s)) return mp[s];
        vector<string> ans;
        for(int i=1; i<=s.size(); i++){
            string tmp = s.substr(0,i);
            if(st.find(tmp)!=st.end() ){
                if (i == s.size()) {
                    ans.push_back(tmp);
                    break;
                }
                vector<string> res = recur(s.substr(i), st, mp);
                for(auto x : res) ans.push_back(tmp + " " + x);
            }
        }
        mp[s] = ans;
        return ans;
    }
};