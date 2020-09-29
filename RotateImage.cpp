class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // reverse(matrix.begin(), matrix.end());
        vector<int> tmp;
        for (int i = 0; i < matrix.size()/2; ++i) {
            // for (int j = 0; j < matrix[i].size(); ++j){
            //     swap(matrix[i][j], matrix[matrix.size()-1-i][j]);
            // }
            matrix[i].swap(matrix[matrix.size()-1-i]);
        }
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = i + 1; j < matrix[i].size(); ++j)
                swap(matrix[i][j], matrix[j][i]);
        }
    }
};