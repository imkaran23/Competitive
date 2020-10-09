class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0, hi = nums.size()-1, lo = 0;
        while(i<=hi){
            if(nums[i]==0) swap(nums[lo++], nums[i++]);
            else if(nums[i]==2) swap(nums[hi--], nums[i]);
            else i++;
        }
    }
};