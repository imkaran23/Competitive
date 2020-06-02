//  https://leetcode.com/problems/minimum-add-to-make-parentheses-valid

class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        for(char c: S){
            if(c==')' && !s.empty() && s.top()=='(') s.pop();
            else s.push(c);
        }
        return s.size();
    }
};