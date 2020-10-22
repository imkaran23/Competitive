class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> nums(n);
        for(int i=1; i<=n; i++) nums[i-1] = i;
        vector<int> taken(n,0), temp, ans;
        bt(ans, taken, temp, nums, k);
        
        string res = "";
        for(int x : ans) res += to_string(x); 
        return res;
    }
    
    void bt(vector<int>& ans, vector<int>& taken, vector<int>& temp, vector<int>& nums, int& k){
        if(!k) return;
        if(temp.size()==nums.size()) {
            if(!--k) ans = temp;
            return;
        }
        
        for(int i=0; i<nums.size(); i++){      
            if(taken[i]) continue;
            temp.push_back(nums[i]);
            taken[i] = 1;
            bt(ans, taken, temp, nums, k);
            taken[i] = 0;
            temp.pop_back();
        }
    }
};

// string getPermutation(int n, int k) {
//     int i,j,f=1;
//     // left part of s is partially formed permutation, right part is the leftover chars.
//     string s(n,'0');
//     for(i=1;i<=n;i++){
//         f*=i;
//         s[i-1]+=i; // make s become 1234...n
//     }
//     for(i=0,k--;i<n;i++){
//         f/=n-i;
//         j=i+k/f; // calculate index of char to put at s[i]
//         char c=s[j];
//         // remove c by shifting to cover up (adjust the right part).
//         for(;j>i;j--)
//             s[j]=s[j-1];
//         k%=f;
//         s[i]=c;
//     }
//     return s;
// }