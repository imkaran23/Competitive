class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int r = matrix.size(), c = matrix[0].size(), ans=0;
        vector<int> heights(c,0);  
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '0') heights[j] = 0;
                else heights[j]++;
            }
            ans = max(ans, largestSquareArea(heights));
        }
        return ans;
    }
    
   int largestSquareArea(vector<int>& heights) {        
        heights.push_back(0);
        stack<int> s;
        int maxi=0;
        
        for(int i=0; i<heights.size() ; i++){
            while(!s.empty() && heights[s.top()]>heights[i]){
                int h = heights[s.top()];
                s.pop();
                int j = s.empty()?0:s.top()+1;
                int k = min(h, i-j);
                maxi = max(maxi, k*k);
            }
            s.push(i);
        }
        return maxi;
    }
};

// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix){
//         int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
//         vector<vector<int>> dp(rows+1, vector<int>(cols+1,0));
//         int maxsqlen = 0;
//         for (int i = 1; i <= rows; i++) {
//             for (int j = 1; j <= cols; j++) {
//                 if (matrix[i-1][j-1] == '1'){
//                     dp[i][j] = min(min(dp[i][j - 1], dp[i - 1][j]), dp[i - 1][j - 1]) + 1;
//                     maxsqlen = max(maxsqlen, dp[i][j]);
//                 }
//             }
//         }
//         return maxsqlen * maxsqlen;
//     }
// };

// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix){
//         int rows = matrix.size(), cols = rows > 0 ? matrix[0].size() : 0;
//         vector<int> dp(cols+1,0);
//         int maxsqlen = 0, prev = 0;
//         for (int i = 1; i <= rows; i++) {
//             for (int j = 1; j <= cols; j++) {
//                 int temp = dp[j];
//                 if (matrix[i-1][j-1] == '1'){
//                     dp[j] = min(min(dp[j - 1], prev), dp[j]) + 1;
//                     maxsqlen = max(maxsqlen, dp[j]);
//                 }
//                 else dp[j] = 0;
//                 prev = temp;
//             }
//         }
//         return maxsqlen * maxsqlen;
//     }
// };