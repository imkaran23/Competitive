class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()==0 || matrix[0].size()==0) return false;
        int r = matrix.size()-1;
        
        while(target < matrix[r][0]){ 
            r--;
            if(r<0) return false;
        }
        
        if(binary_search(matrix[r].begin(), matrix[r].end(), target)) return true;
        else return false;
    }
};