class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, i = 0, n = nums.size();
        if(n==1) return 0;
        while(i<n){
            if(i+nums[i] > n-2) return ++ans;
            int next = 0, dest = 0;
            for(int j=i+1; j<=i+nums[i]; j++){
                if(j+nums[j]>dest){
                    dest = j+nums[j];
                    next = j;
                }
            }
            i=next;
            ans++;
        }
        return 0;
    }
};