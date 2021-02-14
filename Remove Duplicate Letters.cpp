class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> freq(26, 0);
        vector<bool> visited(26, false);
        for (char c : s)
            freq[c-'a']++;
        string ans = "0";
        for (char c : s) {
            freq[c-'a']--;
            if (visited[c-'a']) continue;
            while (c < ans.back() && freq[ans.back()-'a']) {
                visited[ans.back()-'a'] = false;
                ans.pop_back();
            }
            ans += c;
            visited[c-'a'] = true;
        }
        return ans.substr(1); 
    }
};