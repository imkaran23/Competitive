class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<2) return 0;
        auto comp = [](const vector<int>& p1, const vector<int>& p2)
                    { return p1[0] < p2[0] || (p1[0] == p2[0] && p1[1] < p2[1]); };
        sort(intervals.begin(), intervals.end(), comp);
        int i, n = intervals.size(), e=intervals[0][1], ans=0;
        for(i=1; i<n; i++){
            if (intervals[i][0] < e) {
                ans++;
                if (intervals[i][1] < e) e = intervals[i][1];
            }
            else e = intervals[i][1];
        }
        
        return ans;
    }
};