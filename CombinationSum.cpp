//  https://leetcode.com/problems/combination-sum
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        vector<vector<int>> ans;
        bt(candidates, ans, temp, target, 0);
        return ans;
    }
    
    void bt(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int target, int start){
        if(target==0){ 
            ans.push_back(temp);
            return;
        }
        if(target<0) return;
        
        for(int i=start; i<candidates.size(); i++){
            if(candidates[i]>target) return;
            temp.push_back(candidates[i]);
            bt(candidates, ans, temp, target-candidates[i], i);
            temp.pop_back();
        }           
    }   
};

// class Solution {
// public:
//     void combi(vector<int>& candidates, int target,vector<vector<int> > &result,vector<int> &cur, int k, int sum){
//         if(sum==target){
//             result.push_back(cur);
//             return;
//         }
//         if(sum>target) return;
//         for(int i = k; i<candidates.size(); i++){
//             cur.push_back(candidates[i]);
//             combi(candidates,target,result,cur,k,sum+candidates[i]);
//             cur.pop_back();
//             k++;
//         }
//     }
//     vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
//         vector<vector<int> > result;
//         vector<int> cur;
//         combi(candidates, target, result, cur, 0, 0);
//         return result;
//     }
// };