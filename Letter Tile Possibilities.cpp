class Solution {
public:
    int numTilePossibilities(string tiles) {
        int c[26] {};
        int ans = 0;
        for(char x : tiles) c[x-'A']++;
        recur(c, ans);
        
        return ans;
    }
    
    void recur(int c[], int &ans){
        for(int i=0; i<26; i++){
            if(c[i]){
                c[i]--;
                ans++;
                recur(c, ans);
                c[i]++;
            }
        }
    }
};