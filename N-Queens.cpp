// https://leetcode.com/problems/n-queens
class Solution
{
    public:
		vector<vector<string>> solveNQueens(int n){
			vector<string> current(n, string(n, '.'));
			vector<vector<string>> all;
			backtrack(all, current, 0, n);
			return all;
		}
	private:
        void backtrack(vector<vector<string>>& all, vector<string>& current, int row, int &n){
			if (row == n){
				all.push_back(current);
				return;
			}
			for (int col = 0; col < n; ++col){
				if (isValid(current, row, col, n)){
					current[row][col] = 'Q';
					backtrack(all, current, row + 1, n);
					current[row][col] = '.';
				}
			}
		}
		bool isValid(vector<string>& current, int row, int col, int &n){
			for (int i = 0; i != row; ++i){
				if (current[i][col] == 'Q'){
					return false;
				}
			}
			for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
				if (current[i][j] == 'Q'){
					return false;
				}
			}
			for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j){
				if (current[i][j] == 'Q'){
					return false;
				}
			}
			return true;
		}
};