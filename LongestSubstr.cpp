// https://leetcode.com/problems/longest-substring-without-repeating-characters

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<char> v;
        int maxi=0;
        for(char c : s){
            if(v.empty()){
                v.push_back(c);
                maxi=1;
                continue;
            }
            auto it = find(v.begin(),v.end(),c);
            if(it==v.end()){ 
                v.push_back(c);
                if(v.size()>maxi) maxi=v.size();
            }
            else{
                v.erase(v.begin(),it+1);
                v.push_back(c);
            }
        }
        return maxi;
    }
};

// int lengthOfLongestSubstring(string s) {
//         vector<int> dict(256, -1);
//         int maxLen = 0, start = -1;
//         for (int i = 0; i != s.length(); i++) {
//             if (dict[s[i]] > start)
//                 start = dict[s[i]];
//             dict[s[i]] = i;
//             maxLen = max(maxLen, i - start);
//         }
//         return maxLen;
//     }