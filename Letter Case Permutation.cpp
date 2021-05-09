class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        vector <string> ans;
        recur(ans, S, "", 0);
        return ans;
    }
    
    void recur(vector<string>& ans, string& s, string tmp, int i){
        if(tmp.size() == s.size()) {
            ans.push_back(tmp);
            return;
        }
        
        if(isdigit(s[i])){
            tmp += s[i];
            recur(ans,s,tmp,i+1);
        }
        else{
            string tmp1 = tmp;
            tmp1 += (tolower(s[i]));
            recur(ans,s,tmp1,i+1);
            
            string tmp2 = tmp;
            tmp2 += (toupper(s[i]));
            recur(ans,s,tmp2,i+1);
        }
    }
};