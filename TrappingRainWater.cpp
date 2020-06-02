// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) { 
        int result = 0,left_max = 0, right_max = 0, lo = 0, hi = height.size() - 1;
        while (lo <= hi) { 
            if (height[lo] < height[hi]) { 
                if (height[lo] > left_max) left_max = height[lo]; 
                else result += left_max - height[lo]; 
                lo++; 
            } 
            else { 
                if (height[hi] > right_max) right_max = height[hi]; 
                else result += right_max - height[hi]; 
                hi--; 
            } 
        } 

        return result; 
    }
};
