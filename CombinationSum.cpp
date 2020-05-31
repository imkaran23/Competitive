//  https://leetcode.com/problems/combination-sum
class Solution {
public:
    void combi(vector<int>& candidates, int target,vector<vector<int> > &result,vector<int> &cur, int k, int sum){
        if(sum==target){
            result.push_back(cur);
            return;
        }
        if(sum>target) return;
        for(int i = k; i<candidates.size(); i++){
            cur.push_back(candidates[i]);
            combi(candidates,target,result,cur,k,sum+candidates[i]);
            cur.pop_back();
            k++;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int> > result;
        vector<int> cur;
        combi(candidates, target, result, cur, 0, 0);
        return result;
    }
};