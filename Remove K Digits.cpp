class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans;
        int idx = num.size() - k,i;
        for (i=0; i<num.size(); i++) {
            while (ans.size()>0 && ans.back()>num[i] && k>0) {
                ans.pop_back();
                k--;
            }
            ans.push_back(num[i]);
        }
        ans.erase(idx);
        
        i = 0;
        while (i<(int)ans.size()-1 && ans[i]=='0')  i++;
        ans.erase(0, i);
        
        return ans=="" ? "0" : ans;
    }
};