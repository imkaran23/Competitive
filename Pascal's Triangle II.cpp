class Solution {
public:
    vector<int> getRow(int numRows) {
        if(numRows==0) return {1};
        if(numRows==1) return {1,1};
        vector<int> ans, temp;
        temp.push_back(1);
        temp.push_back(1);
        
        for(int i=2; i<=numRows; i++){
            ans.clear();
            ans.push_back(1);
            for(int j=0; j<temp.size()-1; j++) ans.push_back(temp[j] + temp[j+1]);
            ans.push_back(1);
            temp = ans;
        }
        return ans;
    }
};