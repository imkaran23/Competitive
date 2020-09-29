class Solution {
public:
    bool canJump(vector<int>& nums) {
        int i = 0, n = nums.size();
        while(i<n){
            if(i+nums[i] > n-2) return true;
            int next = 0, dest = 0;
            for(int j=i+1; j<=i+nums[i]; j++){
                if(j+nums[j]>dest){
                    dest = j+nums[j];
                    next = j;
                }
            }
            if(nums[next]==0) return false;
            i=next;
        }  
        return true;
    }
};