class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i=0; i<numbers.size()-1; i++){
            if(numbers[i]>target) break;
            if(bs(numbers, i+1, target-numbers[i])) return {i+1, bs(numbers, i+1, target-numbers[i])};
        }
        return {};
    }
    
    int bs(vector<int>& v, int lo, int x){
        int hi = v.size()-1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(v[mid]==x) return mid+1;
            if(v[mid]>x) hi = mid-1;
            else lo = mid+1;
        }
        return 0;
    }
};