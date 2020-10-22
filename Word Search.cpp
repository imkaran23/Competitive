class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(bt(board, word, 0, i, j)) return true;
            }
        }
        return false;
    }
    
    bool bt(vector<vector<char>>& board, const string& word, int idx, int i, int j){
        if(idx == word.size()) return true;
        if(i<0 || j<0 || i==board.size() || j==board[0].size() || board[i][j]!=word[idx]) return false;
        board[i][j] += 27;
        bool ans =     bt(board, word, idx+1, i   , j+1) 
                    || bt(board, word, idx+1, i   , j-1) 
                    || bt(board, word, idx+1, i+1 , j) 
                    || bt(board, word, idx+1, i-1 , j);  
        board[i][j] -= 27;
        return ans;
    }
};