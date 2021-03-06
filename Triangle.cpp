class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
       int n = triangle.size();
        for(int i=n-2;i>=0;i--){
            for(int j=0;j< triangle[i].size();j++){
                triangle[i][j] += min(triangle[i+1][j], triangle[i+1][j+1]);
            }
        }
        return triangle[0][0];
    }
};

// class Solution {
// public:
//     int minimumTotal(vector<vector<int> > &triangle) 
//     {
//         vector<int> mini = triangle[triangle.size()-1];
//         for ( int i = triangle.size() - 2; i>= 0 ; --i )
//             for ( int j = 0; j < triangle[i].size() ; ++ j )
//                 mini[j] = triangle[i][j] + min(mini[j],mini[j+1]);
//         return mini[0];
//     }
// };