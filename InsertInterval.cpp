class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
        int i;
        for (i = 0; i < intervals.size(); i++){
            if(intervals[i].front()>newInterval.front()){ 
                intervals.insert(intervals.begin()+i,newInterval);
                break;
            }
        }
        
        if(i==intervals.size()) intervals.push_back(newInterval);
            
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (i = 1; i < intervals.size(); i++) {
            if (res.back().back() < intervals[i].front()) res.push_back(intervals[i]);
            else res.back().back() = max(res.back().back(), intervals[i].back());
        }
        return res;
    }
};