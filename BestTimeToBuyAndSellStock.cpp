class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), ans = 0;
        for(int i=1; i<n; i++){
            ans = max(ans,prices[i]-prices[i-1]);
            prices[i] = min(prices[i],prices[i-1]);
        }
        return ans;
    }
};