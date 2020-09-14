class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        if(m==0 || n==0 || mat[0][0]==1 || mat[n-1][m-1]==1)
            return 0;
        
        for(int i=0;i<m;i++){
            if(mat[0][i]==1) { 
                mat[0][i] = 0; 
                for(int j=i+1; j<m; j++) mat[0][j]=0;
                break;
            }
            else mat[0][i] = 1;
        }
        for(int i=1;i<n;i++){
            if(mat[i][0]==1){ 
                mat[i][0] = 0; 
                for(int j=i+1; j<n; j++) mat[j][0]=0;
                break;
            }
            else mat[i][0] = 1;
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(mat[i][j] == 1) mat[i][j] = 0;
                else mat[i][j] = mat[i-1][j]+mat[i][j-1];
            }
        }
        
        return mat[n-1][m-1];
    }
};