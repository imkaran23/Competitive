//  https://leetcode.com/problems/generate-parentheses
class Solution {
public:
    void gen(vector<string> &res,string s, int left, int right){
        if(left>right) return;
        if(left==0 && right==0){
            res.push_back(s);
            return;
        }
        if(left>0) gen(res,s+"(",left-1,right);
        if(right>0) gen(res,s+")",left,right-1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        gen(result,"",n,n);
        return result;
    }
};