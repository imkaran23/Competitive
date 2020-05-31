// https://leetcode.com/problems/permutations
class Solution {
public:
    void permute(vector<int>& nums, vector<vector<int> > &result, int start){
        if(start>=nums.size()){
            result.push_back(nums);
            return;
        }
        for(int i=start; i<nums.size(); i++){
            swap(nums[start],nums[i]);
            permute(nums,result,start+1);
            swap(nums[start],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> v;
        permute(nums,result,0);
        return result;
    }
};