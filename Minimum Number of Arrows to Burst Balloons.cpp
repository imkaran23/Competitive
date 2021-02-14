class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n<2) return n;
        auto comp = [](const vector<int>& p1, const vector<int>& p2)
                    { return p1[0] < p2[0]  || (p1[0] == p2[0] && p1[1] < p2[1]);};
        sort(intervals.begin(), intervals.end(), comp);
        int i, e=intervals[0][1], ans=0;
        for(i=1; i<n; i++){
            if (intervals[i][0] <= e) {
                ans++;
                if (intervals[i][1] <= e) e = intervals[i][1];
            }
            else e = intervals[i][1];
        }
        
        return intervals.size()-ans;
    }
};