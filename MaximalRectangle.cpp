class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int r = matrix.size(), c = matrix[0].size(), ans=0;
        vector<int> heights(c,0);  
        
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (matrix[i][j] == '0') heights[j] = 0;
                else heights[j]++;
            }
            ans = max(ans, largestRectangleArea(heights));
        }
        return ans;
    }
    
   int largestRectangleArea(vector<int>& heights) {        
        heights.push_back(0);
        stack<int> s;
        int maxi=heights[0];
        
        for(int i=0; i<heights.size() ; i++){
            while(!s.empty() && heights[s.top()]>heights[i]){
                int h = heights[s.top()];
                s.pop();
                int j = s.empty()?0:s.top()+1;
                maxi = max(maxi,h*(i-j));
            }
            s.push(i);
        }
        return maxi;
    }
};

