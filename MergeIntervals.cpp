class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if(intervals.size()==0 || intervals.size()==1) return intervals;
        sort(intervals.begin(),intervals.end());
        
        // int i=0;
        // while(i<intervals.size()-1){
        //     while(i<intervals.size()-1 && intervals[i][1]>=intervals[i+1][0]){ 
        //         intervals[i][1] = max( intervals[i][1], intervals[i+1][1]);
        //         intervals.erase(intervals.begin()+i+1);
        //     }
        //     i++;
        // }
        
        // auto it = intervals.begin();
        // while(it!=intervals.end()-1){
        //     while( *(it->end()-1) >= *((it+1)->begin()) ){ 
        //         *(it->end()-1) = max(*((it+1)->end()-1), *(it->end()-1));
        //         intervals.erase((it+1));
        //         if(it+1==intervals.end()) break;
        //     }
        //     if(it!=intervals.end()-1) it++;
        // }
        
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            if (res.back().back() < intervals[i].front()) res.push_back(intervals[i]);
            else res.back().back() = max(res.back().back(), intervals[i].back());
        }
        return res;
    }
};