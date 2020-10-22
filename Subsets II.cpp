class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> taken(nums.size(),0), temp;
        ans.push_back({});
        bt(ans, taken, temp, nums, 0);
        return ans;
    }
    
    void bt(vector<vector<int>>& ans, vector<int>& taken, vector<int>& temp, vector<int>& nums, int start){       
        for(int i=start; i<nums.size(); i++){
            if(i>start && nums[i]==nums[i-1]  && !taken[i-1]) continue;
            temp.push_back(nums[i]);
            taken[i] = 1;
            ans.push_back(temp);
            bt(ans, taken, temp, nums, i+1);
            taken[i] = 0;
            temp.pop_back();
        }
    }
};