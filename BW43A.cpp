class Solution {
public:
    int totalMoney(int n) {
        int k = 1, ans=0, x=1;
        
        for(int i=1; i<=n; i++){
            ans += x;
            x++;
            if(i%7==0){
                k++;
                x=k;
            }
        }
        return ans;
    }
};