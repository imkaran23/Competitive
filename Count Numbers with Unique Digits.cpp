class Solution {
    int dp[9];
public:
    Solution(){ 
        dp[0]=1;
        dp[1]=10;
        dp[2]=91;      
        for(int i=3; i<9; i++)
            dp[i] = dp[i-1] + 9 * permutation(9, i-1);
    }
    
    int permutation(int n, int r){
        if(r == 0) return 1;
        else return n * permutation(n - 1, r - 1);
    }
    
    int countNumbersWithUniqueDigits(int n) {
        return dp[n];  
    }
};