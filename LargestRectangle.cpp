// https://leetcode.com/problems/largest-rectangle-in-histogram
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0) return 0;
        
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