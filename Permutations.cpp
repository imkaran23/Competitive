class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> taken(nums.size(),0), temp;
        bt(ans, taken, temp, nums);
        return ans;
    }
    
    void bt(vector<vector<int>>& ans, vector<int>& taken, vector<int>& temp, vector<int>& nums){
        if(temp.size()==nums.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=0; i<nums.size(); i++){
            if(taken[i]) continue;
            temp.push_back(nums[i]);
            taken[i] = 1;
            bt(ans, taken, temp, nums);
            taken[i] = 0;
            temp.pop_back();
        }
    }
};