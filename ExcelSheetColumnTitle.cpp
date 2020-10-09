class Solution {
public:
    string convertToTitle(int n){
        string ans = "";
        while(n){
           ans = (char)(( (n-1)%26) + 65) + ans;
           n = (n-1)/26;
        } 
        return ans;
    }
};