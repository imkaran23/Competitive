class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int i,j,len=nums.size(),m=0,mi;
        if(len<2) return nums;
        vector<int> dp(len,0), son(len,0);
        sort(nums.begin(),nums.end());
        
        for(i=0;i<len;i++){
            for(j=i;j>=0;j--){
                if(nums[i]%nums[j]==0 && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    son[i]=j;
                }
            }
            if(dp[i]>m){
                m=dp[i];
                mi=i;
            }
        }
        vector<int> re;
        for(i=0;i<m;i++){
            re.push_back(nums[mi]);
            mi=son[mi];
        }
        return re;
    }
};

// class Solution {
// public:
//     vector<int> largestDivisibleSubset(vector<int>& nums) {
//         int n = nums.size();
//         if(n<2) return nums;
//         sort(nums.begin(),nums.end());
        
//         vector<int> v[n];
//         v[0].push_back(nums[0]);
//         int k=1;
        
//         for(int i=1; i<n; i++){
//             bool flag = true;
//             for(int j=0; j<k; j++){
//                 if(nums[i]%v[j].back() ==0){
//                     v[j].push_back(nums[i]);
//                     flag=false;
//                 }
//             }
//             if(flag) {
//                 v[k].push_back(nums[i]);
//                 k++;
//             }
//         }
        
//         int idx = 0, tmp = v[0].size();
//         for(int i=1; i<n; i++) if(v[i].size()>tmp) tmp=v[i].size(),idx=i;
        
//         for(int i=0; i<n; i++){
//             for(int x : v[i]){
//                 cout<<x<<" ";
//             }
//             cout<<"\n";
//         }
        
//         return v[idx];
//     }
// };