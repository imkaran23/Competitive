class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "(";
        int l = 1, r = 0;
        bt(ans, s, l ,r, n);
        return ans;
    }
    
    void bt(vector<string>& ans, string s, int l, int r, int n){
        if(l==n && r==n){ ans.push_back(s) ; return;}
        if(l<n) bt(ans, s + "(", l+1 ,r, n);
        if(r<l) bt(ans, s+")", l ,r+1, n);
    }
};