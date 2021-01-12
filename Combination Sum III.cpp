class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> tmp;
        recur(ans, tmp, k, n, 1);
        return ans;
    }
    
    void recur(vector<vector<int>>& ans, vector<int>& tmp, int k, int n, int idx){
        if(tmp.size()==k && n==0){
            ans.push_back(tmp);
            return;
        }
        else if(tmp.size()==k) return;
        
        for(int i=idx; i<=9; i++){
            tmp.push_back(i);
            recur(ans, tmp, k, n-i, i+1);
            tmp.pop_back();
        }
    }
};