class Solution {
public:
    bool isHappy(int n) {
        map<int, bool> mp;  
        while(true){
            int x = 0;
            while(n){
                x += (n%10)*(n%10);
                n /=10;
            }
            
            if(x==1) return true;
            if(mp.find(x)!=mp.end()) return false;
            n = x;
            mp[x] = true; 
        }
        return false;
    }
};