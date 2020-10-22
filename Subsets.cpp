// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        vector<int> temp;
        bt(ans, temp, nums, 0);
        return ans;
    }
    
    void bt(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int start){        
        for(int i=start; i<nums.size(); i++){
            temp.push_back(nums[i]);
            ans.push_back(temp);
            bt(ans, temp, nums, i+1);
            temp.pop_back();
        }
    }
};

// class Solution {
// public:
//     void sub(vector<int>& nums, vector<vector<int> > &result, vector<int> &v, int k){
//         result.push_back(v);
//         for(int i=k; i<nums.size(); i++){
//             v.push_back(nums[i]);
//             sub(nums,result,v,i+1);
//             v.pop_back();
//         }
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<vector<int>> result;
//         vector<int> v;
//         sub(nums,result,v,0);
//         return result;
//     }
// };