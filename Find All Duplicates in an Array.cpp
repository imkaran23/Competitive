class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int> v;
        
        for(auto x : nums) {
            nums[abs(x)-1] = -nums[abs(x)-1];
            if(nums[abs(x)-1]>0) v.push_back(abs(x));
        }
        
        return v;
    }
};