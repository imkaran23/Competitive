class Solution {
public:
    int titleToNumber(string s) {
        long long ans = 0;
        for(int i=0; i<s.size(); i++) ans = ans*26 + s[i] - 64;
        return ans;
    }
};