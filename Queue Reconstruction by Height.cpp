class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto comp = [](const vector<int>& p1, const vector<int>& p2)
                    { return p1[0] > p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); };
        sort(people.begin(), people.end(), comp);
        vector<vector<int>> ans;
        for (auto& p : people) 
            ans.insert(ans.begin() + p[1], p);
        return ans;
    }
};