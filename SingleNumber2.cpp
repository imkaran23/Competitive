class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one_time=0, two_time=0;
        for(int x : nums){
            two_time |= (one_time & x);
            one_time ^= x;
            int common_bit = ~(one_time & two_time);
            one_time &= common_bit;
            two_time &= common_bit;
        }
        return one_time;
    }
};