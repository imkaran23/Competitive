// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2){
        unordered_map<int,int> mp;
        stack<int> s;
        
        for(int i=0; i<nums2.size(); i++){
            while(!s.empty() && s.top()<nums2[i]){
                mp[s.top()] = nums2[i];
                s.pop();
            }
            s.push(nums2[i]);
        }
        
        for(int i=0; i<nums1.size(); i++){ 
            if(mp[nums1[i]])
                nums1[i] = mp[nums1[i]] ;
            else
                nums1[i] = -1 ;
        }
        
        return nums1;
    }
};


// class Solution {
// public:
//     vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
//         for(int i = 0 ; i<nums1.size() ; i++){
//             int j = find(nums2.begin(),nums2.end(),nums1[i]) - nums2.begin() + 1;
//             if(j==nums2.size()) 
//                 nums1[i] = -1;
//             else{
//                 while(j<nums2.size()){
//                 if(nums2[j] > nums1[i]){ 
//                     nums1[i] = nums2[j]; 
//                     break;
//                 }
//                 else if(j==nums2.size()-1) 
//                     nums1[i] = -1;
//                 j++;
//                 }
//             }
//         }
//         return nums1;
//     }
// };