class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s(nums1.begin(), nums1.end());
        vector<int> ans;
        for (int x : nums2) if(s.erase(x)) ans.push_back(x);
        return ans;
    }
};