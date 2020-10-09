class Solution {
public:
    int candy(vector<int>& ratings) {
        if(ratings.size()<=1) return ratings.size();
        
        vector<int> ans(ratings.size(),1);
        for(int i=1; i<ratings.size(); i++) if(ratings[i]>ratings[i-1]) ans[i] = ans[i-1] + 1;
        
        int sum = ans[ratings.size()-1];
        for(int i=ratings.size()-2; i>=0; i--){
            if(ratings[i]>ratings[i+1]) ans[i] = max(ans[i], ans[i+1] + 1);
            sum += ans[i];
        }
        return sum;
    }
};

// TODO : Peak type approach