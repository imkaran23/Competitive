class Solution {  
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>res;
        unordered_map<string, int>m;
        for(int i = 0; i + 10 <= s.size(); i++){
            if(m[s.substr(i, 10)] == 1) res.push_back(s.substr(i, 10));
            m[s.substr(i, 10)]++;
        }
        return res;
    }
};
