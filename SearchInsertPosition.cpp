class Solution {
public:
    int searchInsert(vector<int>& v, int target) {
        int low=0, high=v.size()-1;
        
        while(low<=high){ 
            if(low==high) break;
            int mid = low + (high-low)/2;
            if(v[mid]==target) return mid;
            if(v[mid]>target) high = mid-1;
            else low = mid+1;
        }
        
        if(target>v[low]) return low+1;
        else return low;
    }
};

// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int low = 0, high = nums.size()-1;
//         while (low <= high) {
//             int mid = low + (high-low)/2;
//             if (nums[mid] < target) low = mid+1;
//             else high = mid-1;
//         }

//         return low;
//     }
// };