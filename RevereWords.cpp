// https://leetcode.com/problems/reverse-words-in-a-string/ 
#include <bits/stdc++.h> 

class Solution {
public:
    string reverseWords(string s) {
    
        int k = 0;
        while(s[k]==' '){ k++;}
        string ans = "";
        int high = s.size()-1,low;
        
        for(low = s.size() - 1; low>=k ; low--){
            if(s[low]!=' ') continue;
            if(s[low+1]==' '){ high = low-1; continue;}
            ans += s.substr(low+1, high - low);
            if(ans!="") ans+=" ";
            high = low - 1;
        }
        ans += s.substr(low+1 , high - low);
        return ans;
    }
};