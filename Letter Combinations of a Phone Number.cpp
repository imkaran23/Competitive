class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char, string> mp;
        
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        bt(mp, ans, "", digits, 0);

        return ans;
    }
    
    void bt(unordered_map<char, string>& mp, vector<string>& ans, string s, const string& digits, int idx){
        if(s.size()==digits.size()){ if(s!="") ans.push_back(s); return;}
        for(int i=0; i<mp[digits[idx]].size(); i++)
            bt(mp, ans, s + mp[digits[idx]][i], digits, idx+1);
    }
};