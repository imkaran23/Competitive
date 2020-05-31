// https://leetcode.com/problems/letter-combinations-of-a-phone-number
class Solution {
public:
    void get(string digits, vector<string> &res, map<char,string> mp, string s){
        if(digits.size()==0){
            if(s!="") res.push_back(s);
            return;
        }
        for(int i=0; i<mp[digits[0]].size() ; i++){
            s += mp[digits[0]][i];
            get(digits.substr(1,digits.size()),res,mp,s);
            s = s.substr(0,s.size()-1);
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char,string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        
        vector<string> result;
        get(digits,result,mp,"");
        return result;
    }
};