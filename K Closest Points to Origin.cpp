class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        auto comp = [](const vector<int>& p1, const vector<int>& p2){
            return p1[0]*p1[0] + p1[1]*p1[1] < p2[0]*p2[0] + p2[1]*p2[1];
        };
    
        sort(points.begin(), points.end(), comp);
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};