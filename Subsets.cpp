// https://leetcode.com/problems/subsets
class Solution {
public:
    void sub(vector<int>& nums, vector<vector<int> > &result, vector<int> &v, int k){
        result.push_back(v);
        for(int i=k; i<nums.size(); i++){
            v.push_back(nums[i]);
            sub(nums,result,v,i+1);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> v;
        sub(nums,result,v,0);
        return result;
    }
};