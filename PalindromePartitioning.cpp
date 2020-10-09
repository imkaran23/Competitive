class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> v(n+1,0);
        for(int i=0; i<n+1; i++) v[i] = i-1;
        
        for(int i=0; i<n; i++){
            for(int j=0; i-j >=0 && i+j<n && s[i-j]==s[i+j]; j++) v[i+j+1] = min( 1 + v[i-j], v[i+j+1]);
            
            for(int j=1; i-j+1 >=0 && i+j<n && s[i-j+1]==s[i+j]; j++) v[i+j+1] = min( 1 + v[i-j+1], v[i+j+1]);
        }
        
        return v[n];
    }
};