class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0; 
        int i = 0, j=0, ans = 0;
        while(true){
            while( i< prices.size()-1 && prices[i+1]<prices[i]) i++;
            if(i==prices.size()) break;
            j = i+1;
            while(j<prices.size() && prices[j]>prices[j-1]) j++;
            ans += prices[j-1]-prices[i];
            i = j;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int ans = 0;
//         for (int i = 1; i < prices.size(); i++) {
//             if (prices[i] > prices[i - 1])
//                 ans += prices[i] - prices[i - 1];
//         }
//         return ans;
//     }
// };