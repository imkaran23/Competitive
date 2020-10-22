class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums(n), temp;
        for(int i=1; i<=n; i++) nums[i-1] = i;
        vector<vector<int>> ans;
        bt(ans, temp, nums, k, 0);     
        return ans;
    }
    
    void bt(vector<vector<int>>& ans, vector<int>& temp, vector<int>& nums, int& k, int start){
        if(temp.size()==k) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=start; i<nums.size(); i++){      
            temp.push_back(nums[i]);
            bt(ans, temp, nums, k, i+1);
            temp.pop_back();
        }
    }
};


// class Solution {
// public:
//     vector<vector<int>> combine(int n, int k) {
//         vector<int> temp;
//         vector<vector<int>> ans;
//         bt(ans, temp, n, k, 1);     
//         return ans;
//     }
    
//     void bt(vector<vector<int>>& ans, vector<int>& temp,  int& n, int k, int start){
//         if(!k) {
//             ans.push_back(temp);
//             return;
//         }
        
//         for(int i=start; i<=n; i++){      
//             temp.push_back(i);
//             bt(ans, temp, n, k-1, i+1);
//             temp.pop_back();
//         }
//     }
// };
