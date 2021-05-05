class Solution {
public:
    string getHappyString(int n, int k) {
        int z = pow(2,n-1);
        string ans;
        
        if (k>3*z) return "";
        else if (k>2*z) ans = "c";
        else if (k>z) ans = "b";
        else ans = "a";
        
        recur(n,k,"",ans);
        return ans;
    }
    
    void recur(int& n, int& k, string s, string& ans){
        if(s.size()==n){
            --k;
            if(k==0) ans = s;
            return;
        }
        
        for(char c='a'; c<'d'; c++){
           if(s.empty() || c!=s.back()){
                s+=c;
                recur(n, k, s, ans);
                s.pop_back();
           }
        }
    }
};