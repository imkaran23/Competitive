class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        if(n<2) return false;
        unordered_set<int> s;
        for (int i = 0; i < n; i++) {
            if (i > k) s.erase(nums[i-k-1]);
            if (!s.insert(nums[i]).second) return true;
        }
        return false;
    }
};