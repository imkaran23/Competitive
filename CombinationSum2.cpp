// class Solution {
// public:
//     vector<vector<int> > combinationSum2(vector<int> &num, int target) 
//     {
//         vector<vector<int>> res;
//         sort(num.begin(),num.end());
//         vector<int> local;
//         findCombination(res, 0, target, local, num);
//         return res;
//     }
//     void findCombination(vector<vector<int>>& res, const int order, const int target, vector<int>& local, const vector<int>& num)
//     {
//         if(target==0)
//         {
//             res.push_back(local);
//             return;
//         }
//         else
//         {
//             for(int i = order;i<num.size();i++) 
//             {
//                 if(num[i]>target) return;
//                 if(i&&num[i]==num[i-1]&&i>order) continue;
//                 local.push_back(num[i]),
//                 findCombination(res,i+1,target-num[i],local,num);
//                 local.pop_back();
//             }
//         }
//     }
// };

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
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
            if(i && i>start && candidates[i]==candidates[i-1] ) continue;
            temp.push_back(candidates[i]);
            bt(candidates, ans, temp, target-candidates[i], i+1);
            temp.pop_back();
        }           
    }   
};